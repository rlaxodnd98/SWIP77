// 23_상수멤버함수.cpp
#include <iostream>
using namespace std;

// * 멤버 데이터의 이름 규칙
// 1) x_
// 2) _x => 권장되지 않습니다.
// 3) m_x
// 4) mX

class Point {
    int x_;
    int y_;

public:
    Point(int x, int y)
        : x_ { x }
        , y_ { y }
    {
    }

    // * 상수 멤버 함수는 멤버 데이터를 const 취급합니다.
    // * 멤버 함수를 설계할 때, 내부의 상태(멤버 데이터)를 변경하지 않을 경우
    //   반드시 상수 멤버 함수로 만들어야 합니다.
    void Print() const // 상수 멤버 함수
    {
        // x_ = 10;
        // y_ = 20;
        cout << x_ << ", " << y_ << endl;
    }

    void Move(int ax, int ay)
    {
        x_ += ax;
        y_ += ay;
    }
};

// const T*
// const T&
// const T
//  => 상수 멤버 함수만 호출이 가능합니다.

void foo(const Point* pt)
{
    pt->Print();
}

void foo(const Point& pt)
{
    pt.Print();
}

int main()
{
    const Point c { 100, 200 };
    c.Print();

    Point pt { 10, 20 };
    pt.Print();
    pt.Move(10, 20);

    foo(pt);
}
