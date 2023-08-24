// 4_변수3.cpp
#include <iostream>
using namespace std;

int main()
{
    int a;
    // a의 타입은 무엇인가요?
    // : int

    int* p;
    // p의 타입은 무엇인가요?
    // : int*

    int x[3] = { 10, 20, 30 };
    // x의 타입은 무엇인가요?
    // : int[3]
    cout << sizeof(x) << endl; // 12
    cout << sizeof(int[3]) << endl; // 12

    // 배열의 이름은 배열의 첫번째 원소의 주소로 해석됩니다.
    //  : Decay
    //   예외: sizeof, &

    p = x; // &x[0]
    cout << sizeof(p) << endl; // 8

    // x는 int[3] 배열로 해석됩니다.
    // int[3] 배열을 가르키는 포인터 타입이 필요합니다.
    int(*p2)[3] = &x;
}
