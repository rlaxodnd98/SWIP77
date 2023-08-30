// 4_변수3.cpp
#include <iostream>
using namespace std;

// Decay 예외
// 1) sizeof
// 2) &(address)
// 3) &(reference)

#if 0
int main()
{
    int x[3] = { 10, 20, 30 };

    int n = x[0];

    int* p = x; // &x[0]

    int(*p2)[3] = &x;
}
#endif
// C++11, auto(Type deduction)
// 1) 컴파일 타임에 변수의 타입을 우항의 타입을 기반으로 추론합니다.
// 2) 의존성 있는 타입을 사용할 때,
//    코드가 변경되어도 수정할 필요가 없습니다.
// 3) C의 auto의 키워드를 다른 의미로 사용합니다.

#if 0
int main()
{
    int x[3] = { 10, 20, 30 };

    auto n = x[0]; // n: int

    auto p = x; // p: int*

    auto p2 = &x; // p2: int(*)[3]

    // auto aaa;
    // 우항(초기화) 없이 사용이 불가능합니다.
}
#endif

int main()
{
    const int n = 10; // n: const int
    // n = 100; // Error!

    auto c1 = n; // c1 -> int
    c1 = 1000;

    const auto c2 = n; // c2 -> const int
    // c2 = 1000;

    int x = 10;
    int& r = x; // r의 타입은? int&

    // auto r2 = r; // r2의 타입은? int
    auto& r2 = r; // r2의 타입은? int&
    r2 = 100;
    cout << x << endl;
}
