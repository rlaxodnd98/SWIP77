// 14_접근지정자.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. class의 기본 접근 지정자는 private 입니다.
//    struct의 기본 접근 지정자는 public 입니다.

// 2. private: 외부에서 접근이 불가능하고, 멤버 함수를 통해서만 접근이 가능하다.
//             * friend 선언된 함수/클래스는 접근이 가능합니다.

//     public: 외부에서 접근이 가능하다.

class User {
    string name;
    int age;

public:
    User(string s, int n)
    {
        name = s;
        age = n;
    }

    // 1) 멤버 함수를 제공합니다.
    //  => 접근자 메소드
    //   Getter / Setter
    string GetName() { return name; }
    int GetAge() { return age; }

    // 2) friend
    // : 캡슐화의 정책을 깨뜨리지 않고, 경계를 확장하는데 유용합니다.
    //  > 단위 테스트
    friend void PrintUser(User user);
    friend class UserPrinter;
};

class UserPrinter {
public:
    void Print(User user)
    {
        cout << user.name << ", " << user.age << endl;
    }
};

void PrintUser(User user)
{
    // cout << user.GetName() << ", " << user.GetAge() << endl;
    cout << user.name << ", " << user.age << endl;
}

int main()
{
    // User user("Tom", 42);
    User user { "Tom", 42 };
    PrintUser(user);

    UserPrinter printer;
    printer.Print(user);

    // cout << user.name << ", " << user.age << endl;
}
