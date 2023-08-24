// 7_함수6.cpp
#include <iostream>
using namespace std;

// 최대 공약수
// => 오직 정수를 대상으로만 사용되길 원합니다.
int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a % b) : a;
}

// C++에서 함수 호출을 금지하는 방법
// 1) 구현을 제공하지 않고, 선언만 합니다.
// int gcd(double a, double b);

// => 링크 오류를 의도합니다.
//  - 문제의 원인을 파악하기 어렵습니다.
//  - 의도를 전달하기 어렵습니다.
/*
Undefined symbols for architecture arm64:
  "gcd(double, double)", referenced from:
      _main in 7_함수6-30f281.o
*/

// 2) C++11, Delete function
/*
7_함수6.cpp:33:13: error: call to deleted function 'gcd'
    cout << gcd(3.14, 5.5) << endl;
            ^~~
*/
int gcd(double a, double b) = delete;

int main()
{
    // cout << gcd(3.14, 5.5) << endl; /* Compiler Error */

    cout << gcd(15, 5) << endl;
    cout << gcd(15, 24) << endl;
}
