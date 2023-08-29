// 26_다형성7.cpp
#include <iostream>
using namespace std;

// 1. 부모의 포인터를 통해서 자식 객체를 delete할 때,
//    소멸자도 정적 바인딩을 하기 때문에, 자식의 소멸자를 제대로 호출하지
//    못하는 문제가 발생합니다.
// 2. 부모 클래스의 소멸자는 반드시 가상이어야 합니다.
// 3. 부모 클래스의 소멸자가 가상이면, 자식 클래스의 소멸자도 가상입니다.

class Animal {
public:
    Animal() { cout << "Animal()" << endl; }
    virtual ~Animal() { cout << "~Animal()" << endl; }
};

class Dog : public Animal {
public:
    Dog() { cout << "Dog()" << endl; }
    ~Dog() override { cout << "~Dog()" << endl; }
    // 4. 자식의 소멸자를 작성할 때, override를 통해,
    //    부모의 소멸자가 가상인지 확인할 수 있습니다.
    //    부모의 소멸자가 가상이 아니면, 컴파일 오류가 발생합니다.
};

int main()
{
    Animal* p = new Dog;

    delete p;

    // Dog d;
}
