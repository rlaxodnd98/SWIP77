// 9_레퍼런스.cpp
#include <iostream>
using namespace std;

// 1. C++에서는 레퍼런스 타입이 도입되었습니다.
// => 기존 메모리에 새로운 이름을 부여합니다.

// 2. 포인터와 레퍼런스의 차이점을 이해해야 합니다.
// - 포인터는 변수입니다.
//   포인터는 주소를 저장할 수 있고, 주소를 통해 해당 위치의 값을
//   읽거나 변경할 수 있습니다.
// - 레퍼런스는 기존 메모리에 새로운 이름을 부여합니다.
//   새로운 이름을 통해 해당 메모리에 접근해서, 값을 읽거나
//   변경할 수 있습니다.

#if 0
int main()
{
    int n = 100;

    int& r = n;

    r = 42;
    cout << n << endl;

    n = 100;
    cout << r << endl;
}
#endif

#if 0
int main()
{
    int n = 100;
    int* p = &n;

    *p = 42;
    cout << n << endl;

    n = 100;
    cout << *p << endl;
}
#endif

#if 0
int main()
{
    int n = 100;
    int& r = n;

    cout << &n << endl;
    cout << &r << endl;

    int* p = &n;
    cout << &p << endl;
}
#endif

int main()
{
    // 포인터가 유효하지 않은 경우, NULL로 초기화해야 합니다.
    int* p = NULL;
    cout << p << endl;

    int n = 100;
    // int& r; /* 오류! */
    // : 레퍼런스는 반드시 초기화가 필요합니다.

    // int& r = NULL;
    // : 레퍼런스는 반드시 유효한 변수가 초기값을 지정되어야 합니다.
    //   널 레퍼런스 개념은 C++에서 존재하지 않습니다.
}
