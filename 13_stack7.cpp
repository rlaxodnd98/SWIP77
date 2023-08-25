// 13_stack7.cpp
#include <iostream>
using namespace std;

// 클래스를 헤더와 소스를 분리하는 방법
#include "stack.h"

int main()
{
    Stack s(100);

    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}
