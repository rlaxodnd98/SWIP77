// 20_객체복사2.cpp
#include <iostream>
using namespace std;

//  1) 깊은 복사
class User {
    char* name;
    int age;

public:
    User(const User& rhs)
        : age { rhs.age }
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }

    User& operator=(const User& rhs)
    {
        // 1) 자기 자신인지 확인합니다.
        if (&rhs == this) {
            return *this;
        }

        // 2) 자원을 소유하고 있는 경우, 해지해주어야 합니다.
        delete[] name;

        // 3) 깊은 복사
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
        age = rhs.age;

        return *this;
    }

    User(const char* s, int n)
        : age { n }
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    ~User()
    {
        delete[] name;
    }

    void Print()
    {
        cout << name << "(" << age << ")" << endl;
    }
};

int main()
{
    User user { "Tom", 42 };
    user.Print();

    User other { user };
    other.Print();
}
