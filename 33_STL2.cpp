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
#if 0
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
#endif

#include <vector>
#include <list>
#include <deque>

#if 0
int main()
{
    //                   p1         p2
    //                   |          |
    // vector<int> v = { 10, 20, 30 };
    deque<int> v = { 10, 20, 30 };

    auto p1 = v.begin(); // 시작 위치
    auto p2 = v.end(); // 끝 다음 위치

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
#endif

// 컨테이너(vector, list, deque)가 제공하는 멤버 함수를 통해
// 반복자를 꺼내는 것보다, 일반 함수 begin/end를 사용하는 것이
// 더 좋습니다.
// => 일반 배열도 반복자의 개념으로 사용할 수 있습니다.
#if 0
int main()
{
    // vector<int> v = { 10, 20, 30 };
    int v[] = { 10, 20, 30 };

    auto p1 = begin(v); // 시작 위치
    auto p2 = end(v); // 끝 다음 위치

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
#endif

// Java
//-------
// vector
//   find()
// list
//   find()

// C++
//  vector ---->   <반복자> ---->   find() 일반함수
//  list   ---->
//  deque  ---->

// 컨테이너 --->   반복자   ---> 알고리즘

// C++은 반복자를 통해서, 모든 컨테이너를 대상으로
// 동작하는 일반적인 함수를 제공할 수 있습니다.
// => 알고리즘
template <typename T>
void PrintArray(T begin, T end)
{
    while (begin != end) {
        cout << *begin << endl;
        ++begin;
    }
}

int main()
{
    // int x[3] = { 10, 20, 30 };
    vector<int> x = { 10, 20, 30 };

    // x.begin();
    vector<int>::iterator p = begin(x);
    // 반복자의 실제 타입

    PrintArray(begin(x), end(x));
}
