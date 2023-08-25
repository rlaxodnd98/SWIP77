// 13_stack3.cpp
#include <iostream>
using namespace std;

// 3. 사용자 정의 타입을 만들 때,
//    멤버 데이터(상태)와 멤버 데이터를 조작하는 함수(행위)를 묶을 수 있습니다.
//    => 캡슐화: 상태 + 행위

struct Stack {
    // 멤버 데이터(상태)
    int buff[10];
    int top;

    // 멤버 함수
    void Init()
    {
        top = 0;
    }

    void Push(int n)
    {
        buff[top++] = n;
    }

    int Pop()
    {
        return buff[--top];
    }
};

int main()
{
    Stack s;
    s.Init();

    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}
