// main.cpp
// g++ main.cpp -c
#include <iostream>
using namespace std;

// extern "C" int add(int a, int b);

#include "calc.h"

int main(void)
{
    int result = add(10, 20);
    cout << "result: " << result << endl;

    return 0;
}
