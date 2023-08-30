// 31_연산자오버로딩.cpp
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

    void Print() const
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // 1) 멤버 함수
    // Point Add(const Point& rhs) const
    // Point operator+(const Point& rhs) const
    // {
    //     Point result { x + rhs.x, y + rhs.y };
    //     return result;
    // }

    // 2) 일반 함수
    // friend Point Add(const Point& lhs, const Point& rhs);
    friend Point operator+(const Point& lhs, const Point& rhs);

    Point operator-(const Point& rhs) const
    {
        Point result { x - rhs.x, y - rhs.y };
        return result;
    }

    friend Point operator-(const Point& lhs, const Point& rhs);
};

Point operator-(const Point& lhs, const Point& rhs)
{
    Point result { lhs.x - rhs.x, lhs.y - rhs.y };
    return result;
}

// Point Add(const Point& lhs, const Point& rhs)
Point operator+(const Point& lhs, const Point& rhs)
{
    Point result { lhs.x + rhs.x, lhs.y + rhs.y };
    return result;
}

// 연산자 오버로딩
// 정의: 객체를 대상으로 연산자를 사용하였을 경우,
//      약속된 이름의 멤버 함수 또는 약속된 이름의 일반 함수가 호출되는 문법

// 1) 연산자 우선순위는 변경되지 않습니다.
// 2) 피연산자의 개수도 변하지 않습니다.
//    a + b
//      a.operator+(b)
//      operator+(a, b)
// 3) C++이 제공하지 않는 연산자 재정의도 불가능합니다.
// 4) 연산자 오버로딩이 허용되지 않는 연산자도 있습니다.
//    - ::(범위 연산자)
//      a.b(접근 연산자)
//      ?:(3항 연산자)
// 5) 반드시 피연산자 중 하나는 클래스(사용자 정의 타입)이어야 합니다.
// 6) 반드시 멤버 함수를 통해서만 허용되는 연산자가 있습니다.
//   => 클래스의 설계자만 제공할 수 있습니다.
//    1) 대입 연산자
//       a = b;
//    2) 호출 연산자
//       a(10, 20)
//     3) 임의 접근 연산자
//       a[0]
//     4) 객체 포인터 접근 연산자
//       a->member
//     5) 포인터 참조 연산자
//       *a;

// a + b
//  멤버 함수: a.operator+(b)
//  일반 함수: operator+(a, b)

// a - b
//   멤버 함수: a.operator-(b)
//   일반 함수: operator-(a, b)

int main()
{
    int a = 10;
    int b = 20;
    int r = a + b;

    Point pt1 { 10, 20 };
    Point pt2 { 100, 200 };

    Point result1 = pt1 + pt2;
    // 1) 멤버 함수
    //  Point result1 = pt1.operator+(pt2);

    // 2) 일반 함수
    //  Point result1 = operator+(pt1, pt2);
    result1.Print();

    Point result2 = pt1 - pt2;
    result2.Print();

    // pt1 + pt2
    // 1) 멤버 함수
    // Point result1 = pt1.Add(pt2);
    // result1.Print();

    // 2) 일반 함수
    // Point result2 = Add(pt1, pt2);
    // result2.Print();
}
