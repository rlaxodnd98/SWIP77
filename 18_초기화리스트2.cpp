// 18_초기화리스트2.cpp
#include <iostream>
using namespace std;

// * 초기화 리스트를 반드시 정의해야 하는 경우
// 1) const
// 2) reference
// 3) 클래스의 멤버 데이터 클래스가 기본 생성자를 제공하지 않는 경우

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
