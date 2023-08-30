// 33_STL3.cpp
#include <iostream>
using namespace std;

#include <vector>

#include <algorithm>
// STL에서 컨테이너를 대상으로 검색/정렬 등의 연산을 수행하는
// 일반 함수 집합 => 알고리즘

#if 0
int main()
{
    vector<int> x = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // int x[] = { 1, 2, 3 };

    // Past the end
    // => 검색에서 실패의 의미로 사용됩니다.
    auto p = find(begin(x), end(x), 15);
    if (p != end(x)) {
        cout << *p << endl;
    } else {
        cout << "찾지 못했습니다" << endl;
    }
}
#endif

// C++: bool - true(참) / false(거짓)

// C++ 알고리즘에서 정책을 전달하기 위해서는
// 함수의 인자로 함수 포인터를 전달해야 합니다.
// => 인라인 함수라고 하더라도, 함수 포인터를 통해 호출하면,
//    인라인 최적화가 불가능합니다.

#if 0


int main()
{
    vector<int> x = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

    sort(begin(x), end(x), cmp2);

    for (auto e : x) {
        cout << e << endl;
    }
}
#endif

bool cmp1(int a, int b)
{
    return a > b;
}

bool cmp2(int a, int b) { return a < b; }

class Cmp {
public:
    inline bool operator()(int a, int b) const
    {
        // return a > b;
        return a < b;
    }
};

int main()
{
    vector<int> x = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

    Cmp cmp;
    // sort(begin(x), end(x), cmp);
    //                     Cmp cmp
    // 함수 포인터를 정책으로 전달하면, 인라인 최적화가 불가능합니다.
    // 함수 객체를 정책으로 전달하면, 인라인 최적화가 가능합니다.

    // C++11, 함수 객체를 만드는 새로운 문법이 도입되었습니다.
    //  : Lambda Expression(람다 표현식)
    //  => 실행 가능한 코드 조각을 참조하는 기술
    //  => C++11, 익명의 함수 객체를 생성하는 문법
    sort(begin(x), end(x), [](int a, int b) -> bool {
        return a > b;
    });

    for (auto e : x) {
        cout << e << endl;
    }
}
