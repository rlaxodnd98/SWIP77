// 4_변수5.cpp
#include <iostream>
using namespace std;

// typedef
// => Type aliasing
//    변수를 정의하듯이 타입의 별칭을 만들 수 있습니다.

#if 0
typedef int ARR3[3]; // ARR3 == int[3]

int main()
{
    // int x[3];
    // x: int[3]

    ARR3 x;
    x[0] = 10;
    x[1] = 20;
}
#endif

// C++11에서 typedef를 대체하는 문법이 새롭게 도입되었습니다.
//  : using
//  1) namespace
//     using 선언 / using 지시어
//  2) C++11, type aliasing

// typedef int age_t; // age_t == int
// typedef int array_t[3]; // array_t == int[3]

using age_t = int;
using array_t = int[3];

int main()
{
    age_t age;

    array_t x;
    x[0] = 10;
    x[2] = 20;
}
