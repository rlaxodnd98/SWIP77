// 24_참조반환.cpp
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

    Point& Move(int ax, int ay)
    {
        x += ax;
        y += ay;

        return *this;
    }

    void Print() const { cout << x << ", " << y << endl; }
};

int main()
{
    Point pt { 0, 0 };

    // pt.Move(10, 20);
    // pt.Move(10, 20);
    // pt.Move(10, 20);

    // 자기 자신의 참조를 반환하는 멤버 함수는
    // 아래와 같은 방법으로 함수를 호출할 수 있습니다.
    // => 체이닝
    pt.Move(10, 20)
        .Move(10, 20)
        .Move(10, 20);

    pt.Print();
}
