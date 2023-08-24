// b.c
#include <stdio.h>

// int add(int a, int b);
#include "a.h"

int b_global = 200;

int b_add(int a, int b)
{
    return a + b + 10;
}

int main(void)
{
    int result = b_add(10, 20);

    printf("result: %d\n", result);

    return 0;
}
