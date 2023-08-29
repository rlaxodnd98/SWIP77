// 26_다형성6.cpp
#include <iostream>
using namespace std;

class Car {
public:
    virtual void Start() { cout << "Car Start" << endl; }
};

class Sedan : public Car {
public:
    void Start() override final { cout << "Sedan Start" << endl; }
    // 이제부터 모든 Sedan은 Start를 할때 위의 함수만 사용해야 합니다.
    //  C++11, final
    //   : 멤버함수에서 더이상 오버라이딩이 불가능합니다.
};

// final을 클래스에 지정한 경우, 더이상 상속이 불가능합니다.
class Avante final : public Sedan {
public:
    // void Start() override { cout << "Avante Start" << endl; }
};

// class Avante2 : public Avante { };

int main()
{
    Avante a;
    Car* p = &a;

    p->Start();
}
