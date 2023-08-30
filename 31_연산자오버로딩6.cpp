// 31_연산자오버로딩6.cpp
#include <iostream>
using namespace std;

// 사용자 정의 타입을 기본 타입처럼 동작하도록 만들어 줄 수 있습니다.
// => 기본 타입이 동작하는 방식대로 동작하도록 만들어주어야 합니다.

class Integer {
    int value;

public:
    Integer(int n = 0)
        : value { n }
    {
    }

    // ++x
    Integer& operator++()
    {
        ++value;
        return *this;
    }

    // x++
    Integer operator++(int)
    {
        Integer temp { *this }; // 증가되기 이전의 복사본
        ++value;

        return temp;
    }

    // 아래처럼 friend 함수를 클래스 내부에 제공할 수 있습니다.
    // => 아래 함수는 일반 함수 입니다.
    friend ostream& operator<<(ostream& os, const Integer& v)
    {
        return os << v.value;
    }
};

int main()
{
    Integer x = 0;
    ++ ++x;
    // x.operator++().operator++()
    // x++;
    cout << x << endl;

    int n = 0;
    ++ ++n;
    n++;

    cout << n << endl;
}

// C
//  ++n
//  => 연산의 결과는 증가된 값
//  n++
//  => 연산의 결과는 증가되기 이전의 값
// for (int i = 0 ; i < n; i++)

// C++
//  ++n
//   operator++()

//  => 연산의 결과는 증가된 n
//  n++
//   operator++(int)
//  => 연산의 결과는 증가되기 이전의 복사본

// for (int i = 0 ; i < n; ++i)
