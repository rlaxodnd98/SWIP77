// 9_레퍼런스2.cpp
#include <iostream>
using namespace std;

void Increment1(int x)
{
    ++x;
}

void Increment2(int* px)
{
    // 포인터는 유효성 체크를 해야 합니다.
    if (px) {
        ++(*px);
    }
}

// 1) 레퍼런스는 유효한 초기값을 지정해야 하기 때문에,
//    널 체크 등의 불필요한 코드를 제거할 수 있습니다.
// 2) 별도의 참조 연산 없이 직관적으로 사용할 수 있습니다.
void Increment3(int& rx)
{
    ++rx;
}

int main()
{
    int x = 10;
    // Increment1(x); // Call by value
    // Increment2(&x); // Call by pointer
    Increment2(NULL);
    Increment3(x); // Call by reference

    cout << x << endl;
}
