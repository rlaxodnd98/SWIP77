// 9_레퍼런스3.cpp
#include <iostream>
using namespace std;
// 조금 어렵습니다.

// 1. int&
//  => lvalue reference
//  : lvalue만 참조할 수 있습니다.

#if 0
int main()
{
    int a = 10;

    int& r1 = a; /* OK */
    // int& r2 = 10; /* 10은 rvalue 입니다. */

    cout << &a << endl;
    // => lvalue

    // cout << &10 << endl;
    // => rvalue
}
#endif

// 2. const lvalue reference
//   : const int&
//   const lvalue / lvalue / rvalue 모두 참조할 수 있습니다.
#if 0
void foo(const int& r)
{
    cout << r << endl;
}

int main()
{
    int n = 10;

    foo(n);
    foo(100);
}
#endif

// 3. C++11, rvalue reference
//  : rvalue만 참조할 수 있습니다.
//  - int&&
void foo(int& r)
{
    cout << "lvalue" << endl;
}

void foo(int&& r)
{
    cout << "rvalue" << endl;
}

int main()
{
    int n = 10;
    // int&& r1 = n; /* 실패 */
    int&& r2 = 10; /* OK */

    foo(n);
    foo(10);
}
