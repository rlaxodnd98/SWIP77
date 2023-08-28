// 13_stack10.cpp
#include <iostream>
using namespace std;

#if 0
int buff[10];
int top = 0;

void push(int n)
{
    buff[top++] = n;
}

int pop()
{
    return buff[--top];
}

int main()
{
    push(10);
    push(20);
    push(30);

    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
}
#endif

#if 0
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
    Stack s1;
    Init(&s1);

    Push(&s1, 10);
    Push(&s1, 20);
    Push(&s1, 30);

    cout << Pop(&s1) << endl;
    cout << Pop(&s1) << endl;
    cout << Pop(&s1) << endl;
}
#endif

#if 0
// 캡슐화: 상태(멤버 데이터) + 행위(멤버 함수)
// 변수(상태 + 행위) => 객체
// * 객체의 상태는 객체가 제공하는 멤버 함수를 통해서만 접근되어야 합니다.
//  => 정보 은닉(Information Hiding)
//    "접근 지정자"
//      public: 외부에서 접근이 가능합니다.
//     private: 외부에서 접근이 불가능하고, 오직 멤버 함수를 통해서만
//              접근이 가능합니다.

//     struct: 기본 접근 지정자가 public 입니다.
//      class: 기본 접근 지정자가 private 입니다.
class Stack {
    // 멤버 데이터
    int buff[10];
    int top;

    // 멤버 함수 / 메소드
public:
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
    Stack s1;
    s1.Init();

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    // s1.top = 0; // 잘못된 코드!

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
#endif

#if 0
class Stack {
    int* buff;
    int top;

public:
    // 생성자
    // - 객체가 메모리에 생성되는 시점에 자동으로 호출되는 멤버 함수
    Stack()
    {
        top = 0;
        buff = new int[10];
    }

    // - 생성자는 오버로딩이 가능합니다.
    Stack(int size)
    {
        top = 0;
        buff = new int[size];
    }

    // 소멸자
    // - 객체가 메모리에 파괴되기 직전에 자동으로 호출되는 멤버 함수
    ~Stack()
    {
        delete[] buff;
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
    Stack s1 { 100 };

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
#endif

#if 0
template <typename TYPE>
class Stack {
    TYPE* buff;
    int top;

public:
    Stack()
    {
        top = 0;
        buff = new TYPE[10];
    }

    Stack(int size)
    {
        top = 0;
        buff = new TYPE[size];
    }

    ~Stack()
    {
        delete[] buff;
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

int main()
{
    Stack<double> s1 { 100 };

    s1.Push(10.5);
    s1.Push(2.14);
    s1.Push(3.15);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
#endif

#include <stack>

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();
}
