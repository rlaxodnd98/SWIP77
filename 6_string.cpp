// 6_string.cpp
#include <iostream>
using namespace std;

// * C 문자열
// - 정의: '\0'(널 문자)로 종료되는 char 배열

// * C/C++에서 char는 문자 타입입니다.
// signed 인지 unsigned인지 미지정 동작입니다.

// - char(문자)
// - signed char(부호 있는 1바이트 정수)
// - unsigned char(부호 없는 1바이트 정수)

// * C의 문자열을 직접 다룰 경우 문제점
// 1) 문자열의 연산을 함수를 통해서 수행해야 합니다.
//   strcmp, strcpy, strcat ...
// 2) 문자열의 연산을 수행할 때, 메모리를 직접 관리해야 합니다.
//    메모리가 충분히 확보되지 않은 상태로 연산을 수행할 경우,
//    미정의 동작의 위험성이 있습니다.
#if 0
#include <cstring> // string.h

int main()
{
    char str1[32] = "hello";
    const char* str2 = "hello";
    // str2[0] = 'x';

    if (strcmp(str1, str2) == 0) {
        cout << "Same" << endl;
    }

    // char str2[32] = str1;
    char other[32];
    strcpy(other, str1);
    cout << other << endl;

    strcat(other, " world");
    cout << other << endl;
}
#endif

// C++은 문자열 타입이 제공됩니다.
#include <string>
// std::string
// 1) 연산자를 통해서 문자열의 비교/복사/연결 등의 작업을 직관적으로 수행할 수 있습니다.
// 2) 메모리 관리를 자동으로 수행합니다.
//  => 미정의 동작의 위험성이 적습니다.
//  => 짧은 문자열의 경우는 내부적으로 메모리를 할당하지 않고, 스택 메모리를
//     사용하기 때문에, 성능도 최적화되어 있습니다.(SSO)

int main()
{
    // std::string s1 = "hello";
    std::string s1 = { "hello" };
    std::string s2 { "hello" };

    if (s1 == s2) {
        cout << "Same" << endl;
    } else {
        cout << "Not same" << endl;
    }

    std::string other { s1 }; // other = s1;
    cout << other << endl;

    // other = other + " world";
    other += " world";
    cout << other << endl;
}
