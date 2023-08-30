// 33_STL2.cpp
#include <iostream>
using namespace std;

// 반복자
//  : 배열에서 포인터의 개념과 유사합니다.
#if 0
void PrintArray(int* x, int n)
{
    for (int i = 0; i < n; i++) {
        cout << x[i] << endl;
    }
}

int main()
{
    int x[5] = { 1, 2, 3, 4, 5 };
    PrintArray(x, sizeof(x) / sizeof(x[0]));
}
#endif

// 1) C++에서 선형 자료구조의 구간을
//    [begin, end) => 반개 구간
//     begin: 시작 위치
//       end: 끝 다음 위치(Past the end)

void PrintArray(int* begin, int* end)
{
    while (begin != end) {
        cout << *begin << endl;
        ++begin;
    }
}

int main()
{
    //          p1            p2
    //           |             |
    int x[5] = { 1, 2, 3, 4, 5 };
    PrintArray(x, x + 5);

    int* p1 = x; // &x[0]
    int* p2 = x + 5; // Past the end
}
