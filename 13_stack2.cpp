// 13_stack2.cpp
#include <iostream>
using namespace std;

// 2. 스택의 상태를 사용자 정의 타입으로
//   설계합니다.
//  => 데이터 캡슐화
struct Stack {
    int buff[10];
    int top;
};

void Init(Stack* s)
{
    s->top = 0;
}

void Push(Stack* s, int n)
{
    s->buff[(s->top)++] = n;
}

int Pop(Stack* s)
{
    return s->buff[--(s->top)];
}

int main()
{
    Stack s;
    Init(&s);

    Push(&s, 10);
    Push(&s, 20);
    Push(&s, 30);

    cout << Pop(&s) << endl;
    cout << Pop(&s) << endl;
    cout << Pop(&s) << endl;
}
