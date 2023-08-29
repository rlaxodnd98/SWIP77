// 26_다형성4.cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void Cry() const { cout << "Animal Cry" << endl; }
};

// 1. 부모가 제공하는 멤버 함수를 자식 클래스가 재정의할 수 있습니다.
//   => 함수 오버라이딩(Overriding)
class Dog : public Animal {
public:
    virtual void Cry() const { cout << "Dog Cry" << endl; }
};

// 2. C++의 함수 바인딩: 어떤 함수를 호출할지 결정하는 것
//    Animal* p = &d;
//    p->Cry();
//   1) 정적(static) 바인딩
//    : 컴파일 타임에 컴파일러가 결정합니다.
//      p의 타입을 보고 어떤 클래스의 멤버 함수를 호출할지 결정합니다.
//     "인라인 최적화가 가능합니다."

//   2) 동적(dynamic) 바인딩
//     : 실행 시간에 어떤 함수가 호출될지 결정됩니다.
//       실행 시간에 p의 타입을 조사해서, 어떤 클래스의 멤버 함수를 호출할지
//       결정합니다.
//      "인라인 최적화가 불가능합니다."

//   => 멤버 함수를 virtual 함수로 만들면,
//      동적 바인딩을 수행합니다.

int main()
{
    Animal a;
    Dog d;

    Animal* p = &a;
    p->Cry();

    p = &d;
    p->Cry();
}

#if 0
int main()
{
    Animal a;
    a.Cry();

    Dog d;
    d.Cry();
}
#endif
