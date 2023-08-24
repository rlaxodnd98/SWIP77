// 4_변수3.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int x[3] = { 10, 20, 30 };

    int n = x[0];

    int* p = x;

    int(*p2)[3] = &x;
}
#endif
// C++11, auto
// 1) 컴파일 타임에 변수의 타입을 우항의 타입을 기반으로 추론합니다.
// 2) 의존성 있는 타입을 사용할 때,
//    코드가 변경되어도 수정할 필요가 없습니다.
// 3) C의 auto의 키워드를 다른 의미로 사용합니다.

#if 1
int main()
{

    int x[3] = { 10, 20, 30 };

    auto n = x[0]; // n: int

    auto p = x; // p: int*

    auto p2 = &x; // p2: int(*)[3]
}
#endif
