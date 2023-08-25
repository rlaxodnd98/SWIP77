// 8_제어문.cpp
#include <iostream>
using namespace std;

int main()
{
    int x[5] = { 1, 2, 3, 4, 5 };

    // size_t len = sizeof(x) / sizeof(int);
    constexpr size_t len = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < len; i++) {
        cout << x[i] << endl;
    }

    // C++11, Ranged-for
    for (auto e : x) {
        cout << e << endl;
    }
}
