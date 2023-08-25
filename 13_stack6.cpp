// 13_stack5.cpp
#include <iostream>
using namespace std;

// 5. 객체 내부에서 new를 통해 할당된 메모리는
//    반드시 객체가 파괴되기 전에 delete 되어야 합니다.

//  객체가 파괴되기 직전에 자동으로 호출되는 약속된 멤버 함수가 있습니다.
//   : 소멸자(Destructor) 함수
//   1) 함수의 이름은 ~클래스이름 입니다.
//   2) 반환값도 없고 반환 타입도 명시하지 않습니다.
//   3) 소멸자는 인자 없는 형태 1개만 제공할 수 있습니다.

class Stack {
private:
    // int buff[10];
    int* buff;
    int top;

public:
    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff;
        // 연속된 메모리는 반드시 delete[]를 사용해야 합니다.
    }

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
