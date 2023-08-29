// 30_다운캐스팅.cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual ~Animal() { }
};

class Dog : public Animal {
    int color = 42;

public:
    int GetColor() const { return color; }
};

int main()
{
    Animal a;
    Dog d;
    // Animal* p = &d;
    Animal* p = &a;

    // p가 Dog라면,
    // 다운 캐스팅을 수행해야 합니다.
    //  : 부모의 포인터(참조) 타입을 자식의 포인터(참조) 타입으로의 암묵적인
    //    변환이 허용되지 않습니다.
    // => 명시적인 캐스팅이 필요합니다.
    //   - static_cast
    //    : 잘못된 타입이 지정되어도, 캐스팅이 수행됩니다.

    // 1. p가 Dog타입인지 조사해야 합니다.
    //   : RTTI(Run Time Type Information)
    //  - typeid
    //     위의 연산자를 통해 타입의 정보를 담은 구조체를 얻을 수 있습니다.
    //      : type_info
    //     => 가상함수 테이블에 저장이 됩니다.

    //    1) typeid(클래스)
    //    2) typeid(객체)
#if 0
    if (typeid(Dog) == typeid(*p)) {
        Dog* pDog = static_cast<Dog*>(p);
        cout << pDog->GetColor() << endl;
    } else {
        cout << "Dog 타입이 아닙니다." << endl;
    }
#endif

    Dog* pDog = dynamic_cast<Dog*>(p);
    // 실행 시간에 타입을 조사합니다.
    // 잘못된 타입인 경우, nullptr을 반환합니다.
    // => 다운 캐스팅

    if (pDog) {
        cout << pDog->GetColor() << endl;
    } else {
        cout << "Dog 타입이 아닙니다." << endl;
    }

    // C++ 다운 캐스팅
    // 1) static_cast
    //  : 컴파일 타임에 캐스팅을 수행합니다. 오버헤드가 없습니다.
    //    잘못된 타입을 감지할 수 없습니다.
    //  "실패 가능성이 없는 다운 캐스팅에서 이용합니다."

    // 2) dynamic_cast
    //   : 실행시간에 캐스팅을 수행합니다. 잘못된 타입의 경우
    //     nullptr을 반환합니다.
    //   : 가상함수 테이블에 존재하는 타입 정보를 이용합니다.
    //     가상함수 테이블이 없는 경우, 컴파일 오류가 발생합니다.

    //  "실패 가능성이 존재하는 다운 캐스팅에서 이용합니다."
}

// C++ 캐스팅 연산자 4가지
// 1) static_cast
// 2) reinterpret_cast
// 3) const_cast
// 4) dynamic_cast
