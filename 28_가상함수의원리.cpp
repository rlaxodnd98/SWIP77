// 28_가상함수의원리.cpp
#include <iostream>
using namespace std;

// 1. 가상함수를 사용하면,
//    가상함수가 존재하는 클래스의 객체의 크기가 포인터 크기만큼 늘어납니다.
//     => 가상함수 테이블을 참조하는 포인터

// 2. 가상함수 테이블의 크기는 가상 함수의 개수만큼 유지됩니다.

class Shape {
    int x;
    int y;

public:
    virtual void Draw() const { }
    virtual Shape* Clone() { return nullptr; }
};

class Rect : public Shape {
    int width;

public:
    void Draw() const override { }
};

int main()
{
    Shape s;
    Rect r;

    Shape* p = &s;
    p->Draw();

    p = &r;
    p->Draw();
    p->Clone();
}

#if 0
int main()
{
    Shape s;
    cout << sizeof(s) << endl;

    Rect r;
    cout << sizeof(r) << endl;
}
#endif
