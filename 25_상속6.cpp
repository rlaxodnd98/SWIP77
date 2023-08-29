// 25_상속6.cpp
#include <iostream>
using namespace std;

// "protected 생성자의 의도"
//  : Animal 객체는 생성할 수 없지만,
//    Dog 객체는 생성할 수 있도록 하고 싶습니다.
// => 부모 클래스를 추상(abstract)적인 개념으로 사용하고 싶다.
class Animal {
protected:
    Animal() { }
};

class Dog : public Animal {
public:
    // Dog() : Animal() {}
    //  자식의 생성자에서 부모의 생성자에 접근할 수 있습니다.
};

int main()
{
    // Animal a;
    Dog d;
    // Dog::Dog()
}
