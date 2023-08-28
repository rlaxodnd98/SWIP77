// 23_상수멤버함수2.cpp
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

    void Move(int a, int b)
    {
        x = a;
        y = b;
    }

    void Print() const { cout << x << ", " << y << endl; }
};

class Rect {
    Point leftTop;

public:
    Rect(int x, int y)
        : leftTop { x, y }
    {
    }

    // 값을 반환할 경우, 상수 참조를 사용할 필요가 없습니다.
    // 반환용 임시 객체의 복사 생성/제거 비용이 추가적으로 발생합니다.
    // Point GetLeftTop() const { return leftTop; }

    // 핵심: C++에서는 상수 멤버 함수와 비상수 멤버 함수를 동시에 제공할 수 있습니다.
    Point& GetLeftTop() { return leftTop; }

    // 상수 멤버 함수는 멤버 데이터를 상수 취급하기 때문에,
    // 참조를 반환할 경우, 반드시 상수 참조를 반환해야 합니다.
    const Point& GetLeftTop() const { return leftTop; }

    void Print() const { leftTop.Print(); }
};

// 비상수 멤버 함수를 동시에 제공할 경우
// => 객체 내부의 멤버를 참조로 반환할 때

//       Rect r;  -> 비상수 멤버 함수
// const Rect r;  -> 상수 멤버 함수
// const Rect& r; -> 상수 멤버 함수
// const Rect* r; -> 상수 멤버 함수

// 상수 멤버 함수만 제공할 경우
//       Rect r;  -> 상수 멤버 함수
// const Rect r;  -> 상수 멤버 함수
// const Rect& r; -> 상수 멤버 함수
// const Rect* r; -> 상수 멤버 함수

// 비상수 멤버 함수만 제공할 경우
//       Rect r;  -> 비상수 멤버 함수
// const Rect r;  -> X
// const Rect& r; -> X
// const Rect* r; -> X

void foo(const Rect& r)
{
    const Point& pt = r.GetLeftTop();
    pt.Print();
}

int main()
{
    Rect rect { 10, 20 };
    Point& pt = rect.GetLeftTop();
    pt.Move(100, 200);

    rect.GetLeftTop().Move(100, 200);

    rect.Print();

    foo(rect);
}
