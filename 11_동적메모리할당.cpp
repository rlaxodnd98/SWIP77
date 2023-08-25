// 11_동적메모리할당.cpp
#include <iostream>
using namespace std;

// MISRA C
// => 동적 메모리 할당 함수의 사용이 금지되어 있습니다.

#include <cstdlib> // malloc, free
// malloc
//  : void* malloc(size_t size);
// free
//  : void free(void* ptr);

// 1. malloc은 메모리의 크기를 인자로 받고, void*를 반환합니다.
//    C++에서 명시적인 캐스팅이 필요합니다.

// 2. free는 할당 받은 메모리의 주소를 전달받고, 해지합니다.
//    인자로 NULL이 전달될 경우, 아무일도 수행하지 않습니다.

#if 0
int main()
{
    int* p = static_cast<int*>(malloc(sizeof(int)));

    *p = 42;
    cout << *p << endl;

    free(p);
    p = NULL;

    free(p);
}
#endif

// 3. C++은 동적 메모리 할당의 기능을 함수가 아닌,
//    연산자를 통해서 제공합니다.
//    new / delete

// 4. new는 타입을 전달하면, 전달된 타입의 크기 만큼 할당되고,
//    해당 타입의 주소 타입이 반환됩니다.
//   => 명시적인 캐스팅이 필요하지 않습니다.

// 5. delete 연산자를 통해 new를 통해 할당된 메모리를 해지할 수 있습니다.
//    NULL이 전달되었을 때, 아무일도 수행하지 않습니다.
#if 0
int main()
{
    int* p = new int;

    *p = 100;
    cout << *p << endl;

    delete p;
    p = NULL;

    delete p;
}
#endif

// 6. new int[size]를 통해 연속된 메모리를 할당할 수 있습니다.
// 7. 연속된 메모리를 해지할 때는 delete가 아닌 delete[] 연산자를
//    이용해야 합니다.

int main()
{

    int* p2 = new int[1000];
    p2[0] = 10;
    p2[999] = 1000;
    cout << p2[999] << endl;

    delete[] p2; // 주의!!!

    int* p = static_cast<int*>(malloc(sizeof(int) * 1000));
    // int[1000]
    p[0] = 10;
    p[999] = 10;
    cout << p[999] << endl;
    free(p);
}
