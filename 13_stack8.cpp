// 13_stack8.cpp
#include <iostream>
using namespace std;

// 모든 타입에 동작하는 스택을 만들고 싶습니다.
// 스택의 알고리즘은 변하지 않습니다.
// 타입만 다릅니다.
// => Template
// => 클래스도 템플릿으로 만들 수 있습니다.
//   함수 템플릿은 인자를 통해 템플릿의 타입을 컴파일러가 결정할 수 있지만,
//   클래스 템플릿은 결정하기 어려울 때가 많습니다.
//   : 명시적으로 타입을 지정해야 하는 경우가 많습니다.

template <typename TYPE>
class Stack {
private:
    TYPE* buff;
    int top;

public:
    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff;
    }

    Stack(int size)
    {
        cout << "Stack(int)" << endl;
        buff = new TYPE[size];
        top = 0;
    }

    Stack()
    {
        cout << "Stack()" << endl;
        buff = new TYPE[10];
        top = 0;
    }

    void Push(TYPE n)
    {
        buff[top++] = n;
    }

    TYPE Pop()
    {
        return buff[--top];
    }
};

#include <string>

int main()
{
    Stack<string> s(100);

    s.Push("hello");
    s.Push("world");
    s.Push("money");

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}

#if 0
int main()
{
    Stack<double> s(100);

    s.Push(10.5);
    s.Push(20.3);
    s.Push(30.14);

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}
#endif
