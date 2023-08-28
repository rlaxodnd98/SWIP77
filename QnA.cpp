// 4_변수3.cpp
#include <iostream>
using namespace std;

#if 0
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
#endif

// 타입을 해석하는 방법은 식별자를 기준으로 해석합니다.
// int *p3[3];

// 1) p3[3]
//  : p3는 3개의 원소를 가지는 배열 타입입니다.
//    원소의 타입은?

// 2) *p3[3]
//  : 원소의 타입은 포인터입니다.
//    포인터가 참조하는 타입은?

// 3) int *p3[3]
//  : 포인터가 참조하는 타입은 int 입니다.

// p3 [ * ][ * ][ * ]
//      |    |    |
//     int  int  int

// int (*p3)[3]
// 1) (*p3)
//  : p3는 포인터입니다.
//    포인터가 참조하는 타입은?

// 2) (*p3)[3]
//  : 포인터가 참조하는 타입은 3개 원소의 배열입니다.
//    원소의 타입은?

// 3) int (*p3)[3]
//  : 원소의 타입은 int 입니다.

// p3 [*]----------> [[int][int][int]]

#if 0
int main()
{
}
#endif

// 정수
// : C/C++은 정수 타입의 크기가 표준으로 정의되어 있지 않습니다.
//   정의되어 있는 것은 char(1바이트) 타입의 크기만 정해져 있습니다.

//  signed char -> short -> int -> long -> long long
//       1           2       4                 8
//                              MSVC: 4
//                               GCC: 8
//  - C/C++
//    stdint.h / cstdint
#if 0
#include <cstdint>
int main()
{
    int8_t a;
    int16_t b;
    int32_t c;
    int64_t d;
}
#endif

// 구조체의 크기는 멤버 데이터의 총합과 같지 않을 수 있습니다.
// => 구조체 정렬
// => 구조체 내부의 패딩은 컴파일러와 플랫폼에 따라 다르게 생성됩니다.
//  "파일에 구조체의 메모리를 저장하거나,
//   네트워크로 전송하는 경우 패딩을 제거해야 합니다"
//   : packing
//     - Compiler 확장 명령
#pragma pack(1)
struct AAA {
    int a;
    char b;
    double c;
};
// |aa|aa|aa|aa|bb|--|--|--|cc|cc|cc|cc|cc|cc|cc|cc|

struct BBB {
    char a;
    double b;
    int c;
};
// |aa|--|--|--|--|--|--|--|bb|bb|bb|bb|bb|bb|bb|bb|cc|cc|cc|cc|--|--|--|--|

// |--|--|--|aa|aa|aa|aa|--|--|--|--|dd|dd|dd|dd|dd|...
// 5  6  7  8  9  10 11 12 13 14 15 16

int main()
{
    int a;
    // 4바이트 정렬

    double b;
    // 8바이트 정렬

    cout << sizeof(AAA) << endl;
    cout << sizeof(BBB) << endl;
}
