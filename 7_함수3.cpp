// 7_함수3.cpp
#include <iostream>
using namespace std;

// 1. 함수의 인자 정보가 동일하고, 반환 타입만 다른 경우
//    함수의 오버로딩은 허용되지 않습니다.
// int foo() { }
// void foo() { }

// 2. 파라미터의 기본값을 지정하는 경우,
//    모호성 오류가 발생할 가능성이 있습니다.
//  => 오버로딩과 파라미터 기본값의 문법은 같이 사용하지 않는
//     것이 좋습니다.

void foo(int n = 100) { cout << "foo(int)" << endl; }
void foo() { cout << "foo()" << endl; }

int main()
{
    // foo(); /* 모호성 오류! */
}
