// 31_연산자오버로딩8.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개도 제공하지 않으면,
//    컴파일러는 아무일도 하지 않는 기본 생성자를 제공합니다.

// 2. 사용자가 복사 생성자를 제공하지 않으면,
//    컴파일러는 멤버를 복사하는 복사 생성자를 제공합니다.

// 3. 사용자가 대입 연산자 오버로딩을 제공하지 않으면,
//    컴파일러는 멤버를 복사하는 대입 연산자를 제공합니다.

// 4. 사용자가 소멸자를 제공하지 않으면,
//    컴파일러는 아무일도 하지 않는 소멸자를 제공합니다.

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    // 컴파일러가 제공하는 복사 생성자의 형태
    Point(const Point& rhs)
        : x { rhs.x }
        , y { rhs.y }
    {
        cout << "Point(const Point&)" << endl;
    }

    // 컴파일러가 제공하는 대입 연산자의 형태
    Point& operator=(const Point& rhs)
    {
        cout << "operator=(const Point&)" << endl;
        x = rhs.x;
        y = rhs.y;

        return *this;
    }

    void Print() const { cout << x << ", " << y << endl; }
};

int main()
{
    Point pt1 { 10, 20 };
    Point pt3 { 100, 200 };

    Point pt2 = pt1; // 복사 생성자
    pt2.Print();

    pt2 = pt3;
    pt2.Print();

    int a;
    int b;
    int c;

    //-------
    a = b = c = 10;
    // a = b = (c = 10);
    // a = (b = c);
    // a = b;
    // a
}
