// 20_객체복사.cpp
#include <iostream>
using namespace std;

// 1) 객체 내부에서 자원을 할당한 경우,
//    소멸자를 통해서 자원을 해지해야 합니다.

class User {
    char* name;
    int age;

public:
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
