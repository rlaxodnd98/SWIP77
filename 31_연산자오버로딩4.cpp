// 31_연산자오버로딩4.cpp
#include <iostream>
using namespace std;

#if 0
namespace xstd {

class istream {
public:
    istream& operator>>(int& r)
    {
        scanf("%d", &r);
        return *this;
    }

    istream& operator>>(double& r)
    {
        scanf("%lf", &r);
        return *this;
    }
};

istream cin;

}

int main()
{
    int n;
    double d;
    // cin >> n >> d;
    // cin.operator>>(n).operator>>(d)

    xstd::cin >> n >> d;

    cout << n << d << endl;
}
#endif

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    friend ostream& operator<<(ostream& os, const Point& pt);
    friend istream& operator>>(istream& is, Point& pt);
};

// 사용자 정의 타입을 입출력하기 위한 연산재 재정의를 제공하는 방법
ostream& operator<<(ostream& os, const Point& pt)
{
    return os << pt.x << ", " << pt.y;
}

istream& operator>>(istream& is, Point& pt)
{
    return is >> pt.x >> pt.y;
}

int main()
{
    Point pt { 10, 20 };

    cin >> pt;
    // cin.operator>>(pt);
    // cin.operator>>(Point&)

    // operator>>(cin, pt)
    // istream& operator>>(istream& is, Point& pt)

    cout << pt << endl;
}
