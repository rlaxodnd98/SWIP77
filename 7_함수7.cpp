// 7_함수7.cpp
#include <iostream>
using namespace std;

// C++11, 함수를 만드는 새로운 방법이 추가되었습니다.
// - Trailing Return Type

#if 0
int add(int a, int b) { return a + b; }

int (*foo(int a, int b))[3]
{
    static int arr[3] = { 10, 20, 30 };
    return &arr; // int (*)[3]
}

int main()
{
}
#endif

// int (*foo(int a, int b))[3]
// 1) foo(int a, int b)
//  : foo는 (int a, int b)를 인자로 받는 함수 입니다.
//    함수의 반환 타입은?

// 2) (*foo(int a, int b))
//  : 함수의 반환 타입은 포인터 입니다.
//    포인터가 참조하는 타입은?

// 3) (*foo(int a, int b))[3]
//  : 포인터가 참조하는 타입은 3개의 원소를 가지는 배열입니다.
//    배열의 원소 타입은?

// 4) int (*foo(int a, int b))[3]
//  : 배열의 원소 타입은 int 입니다.

// int add(int a, int b)
auto add(int a, int b) -> int
{
    return a + b;
}

// int (*foo(int a, int b))[3]
auto foo(int a, int b) -> int (*)[3]
{
    static int arr[3] = { 10, 20, 30 };
    return &arr; // int (*)[3]
}

// 반환 타입을 생략하면, 컴파일 시간에 추론됩니다.
auto sub(int a, int b)
{
    return a - b;
}

auto goo(int a, int b)
{
    static int arr[3] = { 10, 20, 30 };
    return &arr; // int (*)[3]
}

// 인자 정보를 통해 반환 타입을 결정할 때는
// 반드시 Trailing return type을 사용해야 합니다.
template <typename T1, typename T2>
auto xadd(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

int main()
{
}

// C            -> Go
// C++          -> Rust
// Java         -> Kotlin
// Objective C  -> Swift
