// 31_연산자오버로딩3.cpp
#include <iostream>
using namespace std;

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

// 사용자 정의 타입을 C++의 표준 출력을 통해 처리하는 연산자 재정의 함수입니다.
ostream& operator<<(ostream& os, const Point& pt)
{
    return os << pt.x << ", " << pt.y;
    // return os;
}

int main()
{
    Point pt { 10, 20 };

    cout << pt;
    // * 멤버 함수: 클래스의 설계자만 제공할 수 있습니다.
    // cout.operator<<(pt);
    // cout.operator<<(const Point& pt)

    // * 일반 함수: 누구나 제공할 수 있습니다.
    //  ostream& operator<<(cout, pt)
    //  ostream& operator<<(ostream& os, const Point& pt)

    cout << endl;
}
