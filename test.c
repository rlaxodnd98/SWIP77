#include <stdio.h>
void foo(void) { printf("foo\n"); }
void goo() { printf("goo\n"); }
// 위처럼 사용하는 경우, 잘못된 인자가 전달되는 것을
// 컴파일러가 확인할 수 없습니다.

int main(void)
{
    // foo(10);
    goo(10, 20);

    return 0;
}
