// 13_stack3.cpp
#include <iostream>
using namespace std;

// 3. 사용자 정의 타입을 만들 때,
//    멤버 데이터(상태)와 멤버 데이터를 조작하는 함수(행위)를 묶을 수 있습니다.
//    => 캡슐화: 상태 + 행위

// 상태와 행위를 가지는 변수 => 객체(object)
// * 객체의 상태는 멤버 함수를 통해서만 접근할 수 있어야 합니다.
//   : 정보 은닉(Information Hiding)
//    => 접근 지정자
//      1)  public: 외부에서 접근이 가능합니다.
//      2) private: 외부에서 접근이 불가능하고, 오직 멤버 함수를 통해서만 접근이 가능합니다.

struct Stack {
private:
    // 멤버 데이터(상태)
    int buff[10];
    int top;

public:
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

    s.top = 10; /* 미정의 동작 */

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}
