// 15_생성자2.cpp
#include <iostream>
using namespace std;

#include <cstdlib>

// 1) malloc을 이용해서, 객체를 생성한 경우 생성자가 호출되지 않습니다.
// 2) free를 통해서 객체를 파괴한 경우, 소멸자가 호출되지 않습니다.

// 3) new를 통해서 객체를 생성하면, 할당된 메모리를 대상으로 생성자가 호출됩니다.
// 4) delete를 통해 객체를 파괴하면, 객체의 메모리가 해지되기 전에
//    소멸자가 호출됩니다.

// new
// 1) 동적 메모리 할당
// 2) 생성자 호출

// delete
// 1) 소멸자 호출
// 2) 동적 메모리 해지
class Point {
public:
    Point() { cout << "Point()" << endl; }
    Point(int x, int y) { cout << "Point(int, int)" << endl; }

    ~Point() { cout << "~Point()" << endl; }
};

int main()
{
    // Point* pt = new Point[3];

    Point* pt1 = new Point[3] {
        { 10, 20 },
        {},
        { 30, 40 },
    };

    Point* pt2 = new Point[3] {
        Point(),
        Point(10, 20),
        Point(10, 20),
    };

    delete[] pt1;
    delete[] pt2;
}

#if 0
int main()
{
    // Point* pt = new Point;
    // Point* pt = new Point(10, 20);
    Point* pt = new Point { 10, 20 };
    delete pt;
}
#endif

#if 0
int main()
{
    Point* pt = static_cast<Point*>(malloc(sizeof(Point)));
    free(pt);
}
#endif
