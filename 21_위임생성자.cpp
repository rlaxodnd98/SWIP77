// 21_위임생성자.cpp
#include <iostream>
using namespace std;

// C++11, 위임 생성자
//  정의: 자신의 다른 생성자를 통해 객체를 초기화할 수 있습니다.
//   "생성자에서 다른 생성자를 이용할 수 있습니다."

class Color {
    int red;
    int green;
    int blue;

public:
    void Init() { cout << "Init()" << endl; }
    void Init2() { cout << "Init2()" << endl; }

    Color(int r, int g, int b)
        : red { r }
        , green { g }
        , blue { b }
    {
        Init();
        Init2();
    }

    // 목적: 생성자에서 발생하는 코드 중복을 제거할 수 있습니다.
    Color()
        : Color(0, 0, 0) // 위임 생성자
    {
    }

#if 0
    Color()
        : red { 0 }
        , green { 0 }
        , blue { 0 }
    {
        Init();
        Init2();
    }
#endif
};

int main()
{
    // Color c { 10, 20, 30 };

    Color c;
}
