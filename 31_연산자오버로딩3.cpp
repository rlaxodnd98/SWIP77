// 31_연산자오버로딩3.cpp
#include <iostream>
using namespace std;

// std:ostream cout;

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    friend ostream& operator<<(ostream& os, const Point& pt);
};

// 아래 연산자 재정의 함수의 형태를 기억해야 합니다.
ostream& operator<<(ostream& os, const Point& pt)
{
    os << pt.x << ", " << pt.y;
    return os;
}

int main()
{
    Point pt { 10, 20 };

    cout << pt << endl;
    // 1. 멤버 함수
    //  cout.operator<<(pt)

    // 2. 일반 함수
    //  operator<<(cout, pt)
}
