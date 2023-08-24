// main.c
// gcc main.c -c
#include <stdio.h>

int add(int a, int b);
//                  U _add

int main(void)
{
    int result = add(10, 20);

    printf("result: %d\n", result);

    return 0;
}
