// 18_초기화리스트.cpp
#include <iostream>
using namespace std;

// 1. 초기화와 대입의 차이점을 이해해야 합니다.
//  초기화: 변수(객체)를 만들면서 초기값을 지정하는 행위
//    대입: 이미 만들어진 변수(객체)의 값을 변경하는 행위

// 2. C++에서는 반드시 초기화를 해야하는 경우가 있습니다.
//  1) reference
//  2) const

#if 0
int main()
{
    const int cx;

    int a = 10; // 초기화
    int b(10);

    int& r = a;

    int c = 100;
    c = 42; // 대입
}
#endif

#if 0
class Sample {
    int& r;
    const int c;

public:
    Sample(int& r2, int c2)
    {
        r = r2; // 초기화가 아니라 대입입니다.
        c = c2; // 초기화가 아니라 대입입니다.
    }
};

int main()
{
    Sample s;
}

#endif

// 핵심: 생성자에서 멤버의 초기화를 수행하기 위해서는
//      "초기화 리스트" 문법을 이용해야 합니다.

// * 생성자에서 초기화리스트를 반드시 정의해야 하는 경우
//  1) const 멤버 데이터
//  2) reference 멤버 데이터

class Sample {
    int& r;
    const int c;

public:
    Sample(int& r2, int c2)
        : r(r2)
        , c(c2)
    {
    }
};

#if 0
class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }
};

int main()
{
    int r = 10;
    const int c = 42;

    Sample s(r, c);
}
#endif

// 주의: 초기화 리스트에서 멤버 데이터가 초기화되는 순서는
//      "멤버 데이터가 선언된 순서"대로 초기화됩니다.
class Point {
    int x;
    int y;

public:
#if 0
    Point(int a)
        : y(a)
        , x(y + 10)
    {
    }
#endif
    // - 초기화리스트는 생성자에서만 사용이 가능합니다.
    // - 클래스의 멤버 데이터의 순서대로 초기화리스트를 작성해야 합니다.
    Point(int a)
        : x(a)
        , y(x + 10)
    {
    }

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point pt { 10 };
    pt.Print();
}
