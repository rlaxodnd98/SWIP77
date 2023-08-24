// calc.c
// gcc calc.c -c

// External linkage(외부 연결)
// : 다른 파일에서 접근이 가능합니다.
int add(int a, int b)
{
    return a + b;
}

// External linkage를 갖습니다.
int global = 10;

// Internal linkage
// : 다른 파일에서 접근이 불가능합니다.
static void foo(void) { }

// Internal linkage
static int s = 100;
