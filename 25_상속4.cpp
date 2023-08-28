// 25_상속4.cpp
#include <iostream>
using namespace std;

class Base {
public:
    // Base() { cout << "Base()" << endl; }
    Base(int a) { cout << "Base(int)" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

// 초기화리스트를 반드시 정의해야 하는 경우
// 1) const 멤버
// 2) reference 멤버
// 3) 기본 생성자를 제공하는 하지 않는 멤버 클래스 객체
// 4) 기본 생성자를 제공하지 않는 부모 클래스

class Derived : public Base {
public:
    Derived()
        : Base(42) // 부모의 기본 생성자를 호출하는 코드를 컴파일러가 삽입
    {
        cout << "Derived()" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
    // 컴파일러가 부모의 소멸자를 호출하는 코드를 자동으로 삽입
    //  2> Base::~Base()
};

/*
Base()
Derived()
~Derived()
~Base()
*/

int main()
{
    Derived d;
    // 1) Derived::Derived()
} // 1> Derived::~Derived()
