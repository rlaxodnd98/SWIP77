// 20_객체복사2.cpp
#include <iostream>
using namespace std;

class User {
    char* name;
    int age;

public:
    // C++11, Rvalue reference, Move Constructor(이동 생성자)
    User(User&& rhs)
        : name { rhs.name }
        , age { rhs.age }
    {
        rhs.name = nullptr;
        cout << "User(User&&)" << endl;
    }

    User(const User& rhs)
        : age { rhs.age }
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
        cout << "User(const User&)" << endl;
    }

    User(const char* s, int n)
        : age { n }
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
        cout << "User(const char*, int)" << endl;
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

    // User other { User { "Tom", 42 } };

    // User other { user };
    User other { std::move(user) };
    // C++11, lvalue를 rvalue로 변경할 수 있는 연산이 추가되었습니다.
    //  : std::move

    other.Print();
}
