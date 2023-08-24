// test.cpp

void foo() { }
// 0000000000000000 T __Z3foov

void foo(int a) { }
// 0000000000000004 T __Z3fooi

extern "C" int add(int a, int b);

int add(int a, int b) { return a + b; }
// 0000000000000014 T __Z3addii

// extern "C" int add(int a, int b);
// 0000000000000014 T _add
