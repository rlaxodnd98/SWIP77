// calc.cpp
// g++ calc.cpp -c

extern "C" int add(int a, int b);
// 0000000000000000 T _add

// 0000000000000000 T __Z3addii
int add(int a, int b)
{
    return a + b;
}
