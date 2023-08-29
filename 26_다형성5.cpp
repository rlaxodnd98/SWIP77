// 26_다형성5.cpp
#include <iostream>
using namespace std;

// 1) 부모 클래스의 멤버 함수가 가상함수이면,
//    자식이 재정의한 멤버 함수도 가상함수입니다.

// 2) virtual 문제점
//   - 부모의 멤버 함수가 가상 함수가 아니면,
//     자식이 오버라이딩 하면 안됩니다.
//   - 오버라이딩을 수행할 때,
//     자식이 잘못된 이름을 사용할 경우,
//     오류가 발생하지 않습니다.
//   => C++11, override
//    1) 오버라이딩한 부모의 멤버 함수가 가상 함수가 아니면
//       컴파일 오류가 발생합니다.
//    2) 부모가 제공하지 않는 멤버 함수를 오버라이딩한 경우,
//       컴파일 오류가 발생합니다.
//   결론: 자식이 재정의하는 멤버 함수에는 반드시 override를 지정해야 합니다.

class Animal {
public:
    virtual void Hello() const { cout << "Animal Hello" << endl; }
};

class Dog : public Animal {
public:
    void Hello() const override { cout << "Dog Hello" << endl; } // 1

    // virtual void Hello() const override { cout << "Dog Hello" << endl; } // 2
};

int main()
{
    Animal* p = new Dog;
    p->Hello();

    Dog d;
    Animal& r = d;
    r.Hello();
}
