// 13_stack9.cpp

// 이미 C++ 표준 라이브러리에 모든 타입에 대해서 사용할 수 있는
// 템플릿 기반의 스택이 제공됩니다.
//  : STL(Standard Template Library)

#include <iostream>
using namespace std;

#include <stack>

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    // 스택에서 데이터를 제거하는 연산과,
    // 마지막 요소를 확인하는 연산이 분리되어 있습니다.
    // - 제거: s.pop()
    // - 참조: s.top()
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}
