// 27_추상클래스.cpp
#include <iostream>
using namespace std;

// 순수 가상 함수를 1개 이상 가지는 클래스는 객체를 생성할 수 없습니다.
// => 추상 클래스(abstract class)가 됩니다.
class Shape {
public:
    virtual ~Shape() { }

    // - 부모의 입장에서 Clone / Draw 함수는 구현을 제공할 필요가 없습니다.
    // - 자식 클래스는 반드시 Clone / Draw 함수를 오버라이딩해서 구현을 제공해야 합니다.
    //  => 순수 가상 함수(Pure virtual function)
    virtual Shape* Clone() const = 0;
    virtual void Draw() const = 0;
};

// 자식 클래스가 부모가 제공하는 순수 가상 함수를 구현하지 않으면,
// 자식 클래스도 추상 클래스가 됩니다.
class Rect : public Shape {
public:
    Shape* Clone() const override { return new Rect(*this); }
    void Draw() const override { cout << "Rect Draw" << endl; }
};

int main()
{
    // Shape s; // 객체 생성이 불가능합니다.
    Rect r;
}
