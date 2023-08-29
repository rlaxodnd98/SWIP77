// 17_this.cpp
#include <iostream>
using namespace std;

// 핵심
// : 멤버 함수는 호출할 때, 첫번째 인자로 객체의 주소가 전달됩니다.
//   전달된 객체의 주소는 멤버 함수 안에서 this를 통해서 접근할 수 있습니다.

class Point {
    int x;
    int y;

public:
    // void Point::Set(Point* this, int a, int b)
    // => thiscall
    void Set(int a, int b)
    {
        cout << "this: " << this << endl;
        // x = a;
        this->x = a;

        // y = b;
        this->y = b;
    }

    // 객체의 주소가 전달되지 않습니다.
    // 일반함수와 동일합니다.
    static void foo(int a, int b)
    {
    }
};

void Set(int a, int b)
{
}

int main()
{
    Point::foo(10, 20);
    /*
        mov     edx, 200
        mov     ecx, 100
        call    static void Point::foo(int,int)
    */

    Set(10, 20);
    /*
        mov     edx, 20
        mov     ecx, 10
        call    void Set(int,int)
    */

    Point pt1, pt2;

    cout << "pt1: " << &pt1 << endl;
    pt1.Set(10, 20);
    // Point::Set(&pt1, 10, 20)
    /*
        mov     r8d, 20
        mov     edx, 10
        lea     rcx, QWORD PTR pt1$[rsp]  ; rcx = &pt1;
        call    void Point::Set(int,int)
    */

    cout << "pt2: " << &pt2 << endl;
    pt2.Set(100, 200);
    // Point::Set(&pt2, 100, 200)
}
