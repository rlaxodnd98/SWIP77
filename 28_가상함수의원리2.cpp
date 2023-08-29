// 28_가상함수의원리2.cpp
#include <iostream>
using namespace std;

// 정적 바인딩 /동적 바인딩과 가상 함수 테이블을 이해하기 위한 예제입니다.
#if 0
class AAA {
public:
    void foo() { cout << "AAA foo" << endl; } // 1
};

class BBB {
public:
    void goo() { cout << "BBB goo" << endl; } // 2
};

int main()
{
    AAA aaa;

    BBB* p = reinterpret_cast<BBB*>(&aaa);

    p->goo(); // BBB::goo(p);
}
#endif

#if 1
class AAA {
public:
    virtual void foo() { cout << "AAA foo" << endl; } // 1
};

class BBB {
public:
    virtual void goo() { cout << "BBB goo" << endl; } // 2
};

int main()
{
    AAA aaa;

    BBB* p = reinterpret_cast<BBB*>(&aaa);

    p->goo();
}
#endif
