// 13_stack9.cpp

// 이미 C++ 표준 라이브러리에 모든 타입에 대해서 사용할 수 있는
// 템플릿 기반의 스택이 제공됩니다.
//  : STL(Standard Template Library)

#if 0
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
#endif

#include <iostream>
using namespace std;

#include <vector>

// 정적 배열
//  : 크기가 고정된 배열
// 동적 배열 => vector
// : 연속된 메모리, 데이터가 동적으로 추가될 수 있습니다
// 연결 리스트 => list
// : 논리적으로 연속되는 메모리

int main()
{
    // int x[5] = { 10, 20, 30, 40, 50 };
    vector<int> x = { 10, 20, 30, 40, 50 };
    x[0] = 10;
    x[4] = 1000;
    cout << x[0] << endl;

    x.push_back(100);
    x.push_back(200);
    x.push_back(300);

    for (auto e : x) {
        cout << e << endl;
    }
}
