// 1_시작3.cpp
// C++ 표준 입출력 라이브러리가 있습니다.
// - 헤더의 확장자가 없는 경우가 많습니다.
#include <iostream>
// std::cout -> stdout

#include <stdio.h>
// printf -> stdout

// 1) printf/scanf 서식은 변수의 타입에 따라
//    서식도 같이 변경되어야 합니다.
// - std::cout/cin은 변수의 타입에 따라 자동으로 처리됩니다.
//  => 연산자 오버로딩 + 함수 오버로딩

// 2) scanf를 사용할 때, 변수의 주소를 전달해야 하지만,
//    std::cin은 주소를 전달하지 않습니다.
#if 0
int main()
{
    // int n = 42;
    long n = 42L;
    double d = 3.14;
    printf("%ld %lf\n", n, d);

    std::cout << n << " " << d << std::endl;
}
#endif

// scanf    <-- stdin
// std::cin <-- stdin

int main()
{
    double n;
    scanf("%lf", &n); // Call by reference
    printf("%lf\n", n);

    std::cin >> n;
    std::cout << n << std::endl;
}
