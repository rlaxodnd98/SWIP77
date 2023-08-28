// 19_복사생성자.cpp
#include <iostream>
using namespace std;

// 1) 사용자가 생성자를 1개도 제공하지 않으면,
//    컴파일러는 아무일도 수행하지 않는 기본 생성자를 제공합니다.

// 2) 사용자가 자신과 동일한 타입의 객체를 인자로 받는 생성자(복사 생성자)를
//    제공하지 않으면, 컴파일러는 멤버를 복사하는 복사 생성자를 제공합니다.

// 3) 사용자가 복사 생성자를 제공하면, 복사 생성자도 생성자이기 때문에
//    컴파일러는 기본 생성자를 제공하지 않습니다.

class Point {
    int x = 0;
    int y = 0;

public:
    Point()
    {
        cout << "Point()" << endl;
    }

    // 복사 생성자 형태
    Point(const Point& rhs)
        : x(rhs.x)
        , y(rhs.y)
    {
        cout << "Point(const Point&)" << endl;
    }

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point pt;
    pt.Print();

    // Point other = pt;
    Point other(pt);
    other.Print();

    Point o1 = pt;
    Point o2(pt);
    Point p3 = { pt };
    Point p4 { pt };
}
