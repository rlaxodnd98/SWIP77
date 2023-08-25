// 13_stack5.cpp
#include <iostream>
using namespace std;

// 4. 사용자가 원하는 크기의 스택을 생성하고 싶습니다.
//  => 생성자는 객체를 초기화할 때, 사용자로부터 인자를 전달받을 수 있습니다.
//     "생성자 오버로딩"을 통해서, 다양한 생성자를 제공할 수 있습니다.
//  Stack s;          ===> Stack()
//  Stack s(30);      ===> Stack(int)
//  Stack s(100, 20); ===> Stack(int, int)
//     >> 객체를 생성하는 다양한 방법을 제공할 수 있습니다.

class Stack {
private:
    // int buff[10];
    int* buff;
    int top;

public:
    Stack(int size)
    {
        cout << "Stack(int)" << endl;
        buff = new int[size];
        top = 0;
    }

    Stack()
    {
        cout << "Stack()" << endl;
        buff = new int[10];
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
    // Stack s;
    // Stack s();  => Stack()
    // Stack s{};     Stack()

    Stack s(100);
    //  : Stack(int)

    // s.Init();

    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}
