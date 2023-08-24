// 7_함수4.cpp
#include <iostream>
using namespace std;

// C에서는 함수 호출의 오버헤드를 제거하기 위해서,
// 매크로 함수를 이용합니다.
#if 0
int square(int x) { return x * x; }

int main()
{
    int x = 10;

    cout << x * x << endl;

    cout << square(x) << endl;
}
#endif

#if 0
int square(int x)
{
    return x * x;
}

// - 텍스트 치환이기 때문에, 우선순위 문제가 발생할 수 있습니다.
// 1) 매크로 함수의 인자 영역을 괄호로 감싸야 합니다.
// 2) 매크로 함수의 전체 치환 영역도 괄호로 감싸 주어야 합니다.
#define SQUARE(x) ((x) * (x))

int dbl(int x)
{
    return x + x;
}

#define DBL(x) ((x) + (x))

int main()
{
    int x = 10;

    // cout << square(++x) << endl;
    // cout << SQUARE(++x) << endl;
    // 매크로 함수를 사용할 때, 절대 인자에 대해서 ++, -- 연산을
    // 사용하면 안됩니다.

    ++x;
    cout << SQUARE(x) << endl;

    //    ((++x) * (++x))
    //    => 미정의 동작

    // cout << dbl(x) * dbl(x) << endl;
    // cout << DBL(x) * DBL(x) << endl;

    // cout << square(x + x) << endl;
    // cout << SQUARE(x + x) << endl;
}
#endif

// 인라인 함수
// => 함수를 호출하지 않고, 기계어로 치환합니다.
inline int square(int x)
{
    return x * x;
}

int main()
{
    int x = 10;

    cout << square(x) << endl;
    cout << x * x << endl;
}
