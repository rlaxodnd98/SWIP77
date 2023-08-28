// 22_static.cpp
#include <iostream>
using namespace std;

// int cnt = 0;

// 자동차 객체가 생성된 갯수를 관리하고 싶습니다.
class Car {
    static int cnt; // 정적 멤버 데이터
    int color;

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    static int Count() { return cnt; } // 정적 멤버 함수
    // 멤버 함수는 객체를 생성해야지만 호출이 가능합니다.
    // 정적 멤버 함수는 객체를 생성하지 않아도 호출이 가능합니다.
    //  => 접근 지정자를 사용할 수 있습니다.
};

// 정적 멤버 데이터는 외부 정의가 반드시 필요합니다.
int Car::cnt = 0;

void foo() { }

int main()
{
    foo();

    // 정적 멤버 함수는 클래스이름:: 함수를 접근할 수 있습니다.
    cout << Car::Count() << endl;
}

#if 0
int main()
{
    cout << sizeof(Car) << endl;

    Car c[5];

    Car c1;
    // cout << c1.Count() << endl;

    Car c2;
    // cout << c2.Count() << endl;
}
#endif
