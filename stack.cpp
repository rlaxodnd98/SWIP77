// stack.cpp
#include "stack.h"

// 멤버 함수의 이름 앞에 클래스이름::을 지정해야 합니다.
Stack::~Stack()
{
    delete[] buff;
}

Stack::Stack(int size)
{
    buff = new int[size];
    top = 0;
}

Stack::Stack()
{
    buff = new int[10];
    top = 0;
}

void Stack::Push(int n)
{
    buff[top++] = n;
}

int Stack::Pop()
{
    return buff[--top];
}
