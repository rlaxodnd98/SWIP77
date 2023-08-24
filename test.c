#include <stdio.h>
// void foo(void) { printf("foo\n"); }
// void goo() { printf("goo\n"); }
// 위처럼 사용하는 경우, 잘못된 인자가 전달되는 것을
// 컴파일러가 확인할 수 없습니다.

#if 0
int main(void)
{
    auto int a; // 지역(자동) 변수

    // foo(10);
    // goo(10, 20);

    return 0;
}
#endif

int main(void)
{
    char str1[32] = "hello";
    // char* str2 = "hello"; // 위험합니다.
    const char* str2 = "hello"; // 위험합니다.

    // str2[0] = 'x'; /* 미정의 동작 */
}
