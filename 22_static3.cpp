// 22_static3.cpp
#include <iostream>
using namespace std;

// Singleton
//  : 오직 한개의 객체를 생성하고, 언제 어디서든 동일한 방법을 통해
//    객체를 참조할 수 있습니다.
class Cursor {
    // private 소멸자 의도
    //  - 객체 생성의 정책을 제어하고 싶을 때 사용합니다.
private:
    Cursor() { }
    Cursor(const Cursor&) = delete;

public:
    // 마이어스의 싱글톤
    static Cursor& GetInstance()
    {
        static Cursor instance;
        // 정적 지역 변수는 함수가 최초로 수행되는 시점에 생성되고,
        // 프로그램이 종료할 때까지 유지됩니다.
        return instance;
    }
};

int main()
{
    Cursor& c1 = Cursor::GetInstance();
    Cursor& c2 = Cursor::GetInstance();

    cout << &c1 << endl;
    cout << &c2 << endl;
}
