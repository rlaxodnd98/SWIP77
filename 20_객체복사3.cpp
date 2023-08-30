// 20_객체복사3.cpp
#include <iostream>
using namespace std;

//  2) 참조 계수
class User {
    char* name;
    int age;

    int* ref;

public:
    User(const User& rhs)
        : name { rhs.name }
        , age { rhs.age }
        , ref { rhs.ref }
    {
        ++(*ref);
    }

    User(const char* s, int n)
        : age { n }
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);

        ref = new int { 1 };
    }

    User& operator=(const User& rhs)
    {
        // 1) 자기 자신인지 확인합니다.
        if (&rhs == this) {
            return *this;
        }

        // 2) 자원을 소유하고 있는 경우, 해지해주어야 합니다.
        if (--(*ref) == 0) {
            delete[] name;
            delete ref;
        }

        // 3) 복사
        name = rhs.name;
        age = rhs.age;
        ref = rhs.ref;

        ++(*ref);

        return *this;
    }

    ~User()
    {
        if (--(*ref) == 0) {
            delete[] name;
            delete ref;
        }

        cout << "~User(): " << Ref() << endl;
    }

    int Ref() { return *ref; }

    void Print()
    {
        cout << name << "(" << age << ")" << endl;
    }
};

int main()
{
    User user { "Tom", 42 };
    cout << user.Ref() << endl;

    user.Print();

    User other { user };
    cout << user.Ref() << endl;

    other.Print();
}
