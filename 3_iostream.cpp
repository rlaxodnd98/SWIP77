// 3_iostream.cpp
#include <iostream>
#include <iomanip> // setw

using namespace std;

int main()
{
    // int n = 0xFAFA;
    // 1111 1010 1111 1010
    // - C++11에서는 2진수 상수를 지원합니다.
    //   단일 따옴표를 통해서 가독성을 높일 수 있습니다.
    int n = 0b1111'1010'111'11010;

    printf("%x\n", n);
    printf("%X\n", n);

    // IO Manipulator(IO 조정자)
    cout << hex;
    cout << n << endl;

    cout << uppercase;
    cout << n << endl;

    printf("%10d\n", n);

    cout << dec;
    cout << setw(10) << n << endl;

    printf("%010d\n", n);
    cout << setw(10) << setfill('0') << n << endl;
}
