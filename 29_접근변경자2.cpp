// 29_접근변경자2.cpp
#include <iostream>
#include <vector>
using namespace std;

// Stack을 만들어봅시다.
// vector를 이용해서, 한쪽으로 데이터를 추가하고, 한쪽으로 데이터를 제거하면
// 스택처럼 사용할 수 있습니다.

// 상속을 통해 기존 클래스를 재사용할 수 있습니다.
// => 상속을 재사용의 목적으로 사용하는 것은 좋지 않습니다.
//    포함을 사용하는 것이 좋습니다.

// Adapter Pattern
// : 기존 클래스의 인터페이스를 변경해서,
//   새로운 클래스처럼 사용하는 설계 방법

// private 상속 의도
// : 부모의 구현은 내부적으로 재사용하지만, 인터페이스(부모의 public 기능)은
//   물려 받지 않겠다.
#if 0
template <typename TYPE>
class Stack : private vector<TYPE> {
public:
    void push(const TYPE& n)
    {
        vector<TYPE>::push_back(n);
    }

    TYPE& top()
    {
        return vector<TYPE>::back();
    }

    void pop()
    {
        return vector<TYPE>::pop_back();
    }
};
#endif

#include <deque>
#include <stack>

// 포함을 사용하는 것이 더 효율적입니다.
// 실제 C++의 스택이 아래와 같이 구현되어 있습니다.
template <typename TYPE, typename C = deque<TYPE>>
class Stack {
    // vector<TYPE> v;
    C v;

public:
    void push(const TYPE& n)
    {
        v.push_back(n);
    }

    TYPE& top()
    {
        return v.back();
    }

    void pop()
    {
        return v.pop_back();
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    // s.push_back(100);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}
