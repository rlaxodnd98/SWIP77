// 25_상속3.cpp
#include <iostream>
using namespace std;

// 1. 부모 클래스의 private은 자식 클래스에 접근이 불가능합니다.

// 2. C++ 접근 지정자
//  - private: 외부 접근 불가능, 자식 클래스 접근 불가능
//            friend 클래스/함수 접근이 가능
//  - protected: 외부 접근 불가능, 자식 클래스 접근 가능
//  - public: 외부 접근 가능

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
