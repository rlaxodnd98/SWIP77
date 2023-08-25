// 9_레퍼런스2.cpp
#include <iostream>
using namespace std;

void Increment1(int x)
{
    ++x;
}

void Increment2(int* px)
{
    ++(*px);
}

int main()
{
    int x = 10;
    // Increment1(x); // Call by value
    Increment2(&x); // Call by pointer

    cout << x << endl;
}
