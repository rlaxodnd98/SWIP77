// 13_stack.cpp
#include <iostream>
using namespace std;

// 스택(자료구조, 우선순위 큐)을 만들어봅시다.
// => 가장 마지막에 삽입된 데이터가 우선순위가 높습니다.
//  : LIFO(Last In First Out)

// 1. 전역 변수(상태) / 전역 함수(연산)
//  => 하나의 프로그램에서 여러개의 스택을 제공하기 어렵습니다.

int buff[10];
int top = 0;

void Push(int n)
{
    buff[top++] = n;
}

int Pop()
{
    return buff[--top];
}

int main()
{
    Push(10);
    Push(20);
    Push(30);

    cout << Pop() << endl;
    cout << Pop() << endl;
    cout << Pop() << endl;
}
