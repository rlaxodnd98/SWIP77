// 4_변수4.cpp
#include <iostream>
using namespace std;

// C++11, decltype
//  => 주어진 표현식의 정확한 타입을 구하는 연산자입니다.
//     auto와 다르게 우항(초기화)가 필요하지 않습니다.

int main()
{
    int n = 10;
    // n과 동일한 타입의 변수를 만들고 싶습니다.

    decltype(n) x;
    // x는 n과 동일한 타입이 됩니다.

    const int c1 = 100;
    decltype(c1) c2 = 1000;
    // c2 = 100;
}
