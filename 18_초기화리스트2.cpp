// 18_초기화리스트2.cpp
#include <iostream>
using namespace std;

// * 초기화 리스트를 반드시 정의해야 하는 경우
// 1) const 멤버
// 2) reference 멤버
// 3) 클래스의 멤버 데이터 클래스가 기본 생성자를 제공하지 않는 경우
#if 0
class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x(a)
        , y(b)
    {
    }
};

class Rect {
    Point leftTop;

public:
    // 컴파일러가 생성하는 생성자 형태
    // Rect() : leftTop() {}

    Rect()
        // : leftTop(10, 20)
        : leftTop { 10, 20 }
    {
    }
};

int main()
{
    Rect r;
}
#endif

#include <string>
// C++에서 멤버를 초기화하는 방법 2가지
class User {
    // 2) C++11, 필드 초기화
    string name = "Bob";
    int age = 10;

public:
    User() { }

    // 1) 초기화리스트
    User(string s, int n)
        : name { s }
        , age { n }
    {
    }

    void Print()
    {
        cout << name << ", " << age << endl;
    }
};

int main()
{
    User user;
    // User user { "Tom", 42 };
    user.Print();
}
