// 4_변수2.cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

#if 0
int main()
{
    // Copy Initialization(복사 초기화)
    int n1 = 42;
    int x1[3] = { 10, 20, 30 };
    Point pt1 = { 10, 20 };

    // Direct Initialization(직접 초기화)
    int n2(42);
    int x2[3] { 10, 20, 30 };
    Point pt2 { 10, 20 };
}
#endif

#if 0
// C++11, Uniform Initialization(일관된 초기화)
int main()
{
    // Copy Initialization(복사 초기화)
    int n1 = { 42 };
    int x1[3] = { 10, 20, 30 };
    Point pt1 = { 10, 20 };

    // Direct Initialization(직접 초기화)
    int n2 { 42 };
    int x2[3] { 10, 20, 30 };
    Point pt2 { 10, 20 };
}
#endif

#if 0
int main()
{
    double d = 3.14;
    int n = d;
    // 실수 타입은 정수 타입으로의 암묵적인 변환이 허용됩니다.

    long long l = 100LL;
    int n2(l);
    // 표현 범위가 다른 정수 타입간의 암묵적인 변환이 허용됩니다.
}
#endif

// Uniform Initialization은 Preventing Narrow 기능을
// 제공함으로, 실수가 정수가 되거나, 더 큰 표현범위를 가지는 정수가
// 작은 표현범위로의 정수 타입으로의 암묵적인 변환을 허용하지 않습니다.

int main()
{
    double d = 3.14;
    if (d > INT_MAX || d < INT_MIN) {
        cout << "Overflow" << endl;
    } else {
        int n = { (int)d }; // Copy Initialization
    }

    long long l = 100LL;
    if (l > INT_MAX || l < INT_MIN) {
        cout << "Overflow" << endl;
    } else {
        int n { (int)l }; // Direct Initialization
    }
}
