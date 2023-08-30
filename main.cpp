// main.cpp
// g++ main.cpp -c
#if 0
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
#endif

#include "stack2.h"
#include "a.h"

// 헤더 파일을 제공할 때,
// 두번이상 중복 포함되는 문제를 해결해야 합니다.
// => include guard

int main()
{
    Stack s;
    s.Push();
}
