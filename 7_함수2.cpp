// 7_함수2.cpp
#include <iostream>
using namespace std;

#if 0
// 함수의 인자 타입이 다른 경우,
// C는 동일한 이름의 함수를 여러개 만들 수 없기 때문에,
// 다른 이름을 약속합니다.
int squarei(int x) { return x * x; }
double squared(double x) { return x * x; }

int main()
{
    cout << squarei(10) << endl;
    cout << squared(3.14) << endl;
}
#endif

// C++은 동일한 이름의 함수를 여러개 만들 수 있습니다.
// => 함수의 이름은 동일하지만, 함수의 인자 정보(타입, 개수)가 다른 경우만 허용됩니다.
//  "함수 오버로딩(Overloading)"
//   : Name Mangling
//   => 컴파일 시 함수 심볼의 이름이 함수의 식별자와 인자 정보에
//      의해 결정됩니다.
//   => extern "C"를 통해서 C 컴파일러로 빌드된 함수를 호출하거나,
//      C++ 컴파일러로 빌드된 함수를 C 프로그램에서 호출할 수 있습니다.

int square(int x) { return x * x; }
double square(double x) { return x * x; }
long long square(long long x) { return x * x; }

int main()
{
    cout << square(10) << endl;
    cout << square(3.14) << endl;
    cout << square(1000000000LL) << endl;
}
