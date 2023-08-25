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
