// 31_연산자오버로딩5.cpp
#include <iostream>
using namespace std;

// 1) endl은 함수 입니다.
// 2) ostream&(ostream*) 함수를 인자로 받아서 처리할 수 있는 기능을 제공하고 있습니다.

// IO 조정자가 아래와 같은 형태로 제공되고 있습니다.
ostream& menu(ostream& os)
{
    os << "1. 자장면" << endl;
    os << "2. 짬뽕" << endl;
    os << "3. 탕수육" << endl;
    return os;
}

int main()
{
    cout << menu;

    // cout << "1. 자장면" << endl;
    // cout << "2. 짬뽕" << endl;
    // cout << "3. 탕수육" << endl;
}

#if 0
namespace xstd {
class ostream {
public:
    ostream& operator<<(int n)
    {
        printf("%d", n);
        return *this;
    }

    ostream& operator<<(double d)
    {
        printf("%lf", d);
        return *this;
    }

    ostream& operator<<(char ch)
    {
        printf("%c", ch);
        return *this;
    }

    // endl이 cout에서 처리되는 방식
    ostream& operator<<(ostream& (*f)(ostream& os))
    {
        return f(*this);
    }
};

ostream& endl(ostream& os)
{
    return os << '\n';
}

ostream cout;

}

int main()
{
    xstd::cout << 'A' << 42;

    xstd::cout << xstd::endl;
    // xstd::cout.operator<<(xstd::endl)

    // xstd::endl(xstd::cout);

    // cout << xstd::endl;
}
#endif

// 함수 포인터
// : 함수를 가르키는 포인터 변수
// * 함수의 타입은 함수의 인자와 반환 타입(함수의 시그니처)에 의해서 결정됩니다.
//  => 함수의 시그니처가 동일한 함수는 같은 타입입니다.
#if 0
int add(int a, int b) // int(int, int)
{
    return a + b;
}

int sub(int a, int b) // int(int, int)
{
    return a - b;
}

// * 함수 포인터를 통해 함수의 주소를 담을 수 있고,
//   함수를 호출할 수 있습니다.
int main()
{
    int (*fp)(int, int) = nullptr;

    // C++에서 주로 사용하는 표현 방식
    fp = &add;
    int result = (*fp)(10, 20);
    cout << result << endl;

    // C에서 주로 사용하는 표현 방식
    fp = sub;
    result = fp(100, 20);
    cout << result << endl;
}

// int (*fp)(int, int);
// 1) (*fp)
//  : fp는 포인터 타입입니다.
//    포인터가 참조하는 타입은?
// 2) (*fp)(int, int)
//  : 포인터가 참조하는 타입은 (int, int)인자를 받는 함수입니다.
//    함수의 반환 타입은?
// 3) int (*fp)(int, int);
//   : 함수의 반환 타입은 int 입니다.

// * --------> int(int,int)
#endif
