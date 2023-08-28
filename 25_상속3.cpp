// 25_상속3.cpp
#include <iostream>
using namespace std;

// 1. 부모 클래스의 private은 자식 클래스에 접근이 불가능합니다.

// 2. C++ 접근 지정자
//  - private: 외부 접근 불가능, 자식 클래스 접근 불가능
//            friend 클래스/함수 접근이 가능
//  - protected: 외부 접근 불가능, 자식 클래스 접근 가능
//  - public: 외부 접근 가능
#if 0
class Animal {
protected:
    int age = 10;
};

class Dog : public Animal {
public:
    void Print() const
    {
        cout << age << endl;
    }
};

int main()
{
    Dog d;
    d.Print();
}
#endif

// 자식 클래스가 부모 클래스의 멤버를 직접 사용하는 경우,
// 부모 클래스의 변화가 자식 클래스에 영향을 주는 경우가 많습니다.
// => 자식 클래스와 부모 클래스는 강한 결합이 형성됩니다.

// 핵심:
//   부모의 멤버는 private으로 두고,
//   자식 클래스도 protected 멤버 함수를 통해서 접근해야 합니다.

class Animal {
    int age = 10;

protected:
    int GetAge() const { return age; }
};

class Dog : public Animal {
public:
    void Print() const
    {
        // cout << age << endl;
        cout << GetAge() << endl;
    }
};

int main()
{
    Dog d;
    d.Print();
}
