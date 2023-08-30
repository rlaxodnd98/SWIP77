// 31_연산자오버로딩2.cpp
#include <iostream>
using namespace std;

namespace xstd {
class ostream {
public:
    ostream& operator<<(int n)
    {
        printf("%d", n);
        return *this;
    }

    ostream& operator<<(double d)
    {
        printf("%lf", d);
        return *this;
    }
};

ostream cout;

}

int main()
{
    int n = 42;
    double d = 3.14;

    xstd::cout << n << d;
    // cout.operator<<(n).operator<<(d)
}

#if 0
int main()
{
    int n = 42;
    std::cout << n;
    // std::cout.operator<<(n);
    // std::cout.operator<<(int);

    double d = 3.14;
    std::cout << d;
    // std::cout.operator<<(d)
    // std::cout.operator<<(double)
}
#endif
