// 25_상속2.cpp
#include <iostream>
using namespace std;

#if 0
class Dog {
    int age;
    int color;
};

class Cat {
    int age;
    double speed;
};
#endif

// 부모 클래스 / Base / Super
class Animal {
    int age;
};

// 자식 클래스 / Derived / Sub
// 상속: class 자식클래스: public 부모클래스
// => C++에는 private 상속이라는 개념이 존재하지만,
//    객체지향 설계에서 말하는 일반적인 상속과는 다릅니다.
class Dog : public Animal {
    int color;
};

class Cat : public Animal {
    double speed;
};

int main()
{
    cout << sizeof(Dog) << endl;
    cout << sizeof(Cat) << endl;
}
