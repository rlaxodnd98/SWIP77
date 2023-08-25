// 12_nullptr.cpp
#include <iostream>
using namespace std;

void foo(int n) { cout << "int" << endl; }
void foo(int* p) { cout << "int*" << endl; }

// C++11, NULL을 대체하는 nullptr이 도입되었습니다.
// => nullptr_t 타입으로 설계되어 있습니다.
//  : 포인터 타입으로의 암묵적인 변환이 허용되고,
//    논리 표현식에서 사용할 경우, 거짓으로 판단되는 형태로
//    NULL과 동일하게 동작합니다.

int main()
{
    int* p1 = nullptr;
    if (p1) {
        // ...
    }

    foo(0);
    foo(nullptr);
}

#if 0
int main()
{
    // 정수 0은 포인터 타입으로의 암묵적인 변환이 허용됩니다.
    int* p1 = 0;
    // int* p2 = 100; // Error!

    // #define NULL (void*)0
    int* p3 = NULL;

    foo(0);
    foo(NULL); // Compile error!
    // NULL은 포인터와 정수 타입 간의 모호성 오류의 원인이 됩니다.
}
#endif

//  Effective C++
//  More Effective C++
//  Effective STL
// --------------- C++98/03

//  Effective Modern C++ - C++11/14
