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
};

int main()
{
    Point pt1 { 10, 20 };
    Point pt2 { 100, 200 };
}
