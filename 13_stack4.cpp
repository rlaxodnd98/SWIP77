// 13_stack4.cpp
#include <iostream>
using namespace std;

// 4. 객체가 생성되었을 때, 바로 사용할 수 있는 상태가 되어야 합니다.
//  => 객체가 메모리에 생성되었을 때, 자동으로 호출되는 약속된 멤버 함수가 있습니다.
//     : 생성자(Constructor) 함수
//     1) 멤버 함수의 이름이 클래스의 이름과 동일합니다.
//     2) 반환값도 없고 반환 타입도 명시하지 않습니다.

class Stack {
private:
    // 멤버 데이터(상태) => property
    int buff[10];
    int top;

public:
    Stack()
    {
        cout << "Stack()" << endl;
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

// 추상화
// => 문제를 해결하는데, 필요한 요소만 추리는 과정

int main()
{
    Stack s;
    // s.Init();

    s.Push(10);
    s.Push(20);
    s.Push(30);

    // s.top = 10; /* 미정의 동작 */

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}
