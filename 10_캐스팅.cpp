// 10_캐스팅.cpp
#include <iostream>
using namespace std;

// 명시적인 캐스팅이 필요한 경우가 있습니다.
// 1) Uniform initialization
//    - preventing narrow
// 2) void*를 구체적인 포인터 타입으로의 변환

// 3) const T* -> T*
//    const T& -> T&
//    위의 연산에서 명시적인 캐스팅이 필요합니다.
//  => 타입의 불일치 문제를 해결하기 위한 목적으로 사용해야 합니다.

// 4) 메모리 재해석의 목적으로 사용할 수 있습니다.
//    포인터 타입간의 변환에서 사용할 수 있습니다.

// C의 캐스팅 문제점
// : 용도와 목적을 분석하기 어렵다.
// => C++은 용도와 목적에 따라서 4가지의 캐스팅 연산자를 제공합니다.
#if 0
void foo(int* p)
{
    cout << *p << endl;
}

int main()
{
    double d = 3.14;
    int n = { (int)d };

    long long l = 10000LL;
    int x = { (int)l };

    void* pv = &d;
    double* pd = (double*)pv;
    // C++은 void*를 구체적인 포인터타입으로의 암묵적인 변환이
    // 허용되지 않습니다.

    pv = &n;
    int* pn = (int*)pv;

    const int c = 10;
    const int* pc = &c;
    foo((int*)pc);

    int data = 0x12345678;
    char* pb = (char*)&data;
    printf("%x %x %x %x\n", pb[0], pb[1], pb[2], pb[3]);
}
#endif

// C++ 캐스팅 연산자 4가지
// 1) static_cast
// : 가장 기본적인 C++ 캐스팅 연산자
// "연관성 있는 타입 간의 캐스팅에서 사용합니다."
//   다운 캐스팅: 부모의 포인터(참조) 타입을 자식 포인터(참조)타입으로의 변환
//    => 컴파일 타임에 수행이 되지만, 잘못된 타입을 확인할 수 없습니다.

// 2) reinterpret_cast
// : 메모리 재해석 목적으로 사용됩니다.
//  "포인터 간의 변환에서 이용됩니다."
//  => 잘못 사용할 경우, 미정의 동작의 위험성이 있습니다.

// 3) const_cast
// : 메모리 상수성을 제거해서, 타입의 불일치 등의 문제를 해결하기 위한
//   목적으로 사용합니다.

// 4) dynamic_cast
//  : 다운 캐스팅
//   => 실행 시간에 타입을 조사해서, 다운 캐스팅을 수행합니다.
//      잘못된 타입인 경우, nullptr을 반환합니다.

int main()
{
    // 실수 타입 -> 정수 타입
    double d = 3.14;
    int n1 { static_cast<int>(d) };

    // 더 큰 표현 범위 정수 -> 작은 표현 범위 정수
    long long l = 1000LL;
    int n2 { static_cast<int>(l) };

    // void* -> 구체적인 포인터 타입으로의 변환
    void* pv = &n1;
    int* pn = static_cast<int*>(pv);

    // 메모리 재해석
    int x = 0x12345678;
    // char* pb = static_cast<char*>(&x); // Error!
    char* pb = reinterpret_cast<char*>(&x);
    printf("%X %X %X %X\n", pb[0], pb[1], pb[2], pb[3]);

    // long: MSVC: 4바이트
    //        GCC: 8바이트
    long* pl = reinterpret_cast<long*>(&x);
    cout << *pl << endl; // 미정의 동작

    int n = 100;
    const int* pc = &n;

    // *(static_cast<int*>(pc)) = 10000; // 실패!
    // *(reinterpret_cast<int*>(pc)) = 10000; // 실패!

    *(const_cast<int*>(pc)) = 10000;
    cout << n << endl;
}
