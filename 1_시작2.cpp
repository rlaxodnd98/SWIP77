// 1_시작2.cpp
// https://github.com/yoondev-classroom/cpp_230824

// 1. 확장자
// - C  : .c
// - C++: .cpp, .cc, .cxx ...

// 2. 컴파일러
// - Miscrosoft Visual C/C++ Compiler: MSVC
// - GNU C/C++ Compiler: GCC
// - LLVM Compiler: clang

// 3. C++ 표준
// - 1979년: C++ 탄생, 비야네 스트롭스트룹
// - 1998년: C++ 1차 표준안 - C++98
// - 2003년: C++ 1차 개정안 - C++03
// ---- C++98/03 => C++ 1.0
// - 2011년: 2차 표준안 - C++11 => Modern C++
// - 2014년: C++14
// - C++17
// - C++20
// - C++23

// 4. C++은 C 문법을 지원합니다.
//  => C의 표준과 C++안에서의 C의 표준은 다릅니다.

#if 1
#include <stdlib.h>
#include <stdio.h>

void foo(void) { printf("foo\n"); }
void goo() { printf("goo\n"); } // OK!

int main()
{
    // foo(10);
    // goo(10);

    // return 0;
    // return EXIT_SUCCESS;
    // C++에서는 main 함수의 return을 생략하는 경우,
    // 컴파일러가 자동으로 return 0; 처리해줍니다.
}
#endif

// 표준 입출력
#include <stdio.h>

// stdin(표준 입력 장치)
// stdout(표준 출력 장치)
// stderr(표준 에러 장치)

// UNIX
// => 모든 것이 파일입니다.
// open        일반 파일
// read  ----> 디바이스 특수 파일
// write       네트워크 소켓 파일
// close

int main()
{
    printf("Hello, C++");
    // fprintf(stderr, "Hello, C++");
    while (1) {
    }
}
