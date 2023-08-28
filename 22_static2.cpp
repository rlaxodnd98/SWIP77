// 22_static2.cpp
#include <iostream>
using namespace std;

#if 0
class Sample {
public:
    int a = 10; // 멤버 데이터
    static int s; // 정적 멤버 데이터

    void foo() { cout << "foo" << endl; }
    static void goo() { cout << "goo" << endl; }
};

int Sample::s = 100;

int main()
{
    // 1. 멤버 데이터는 객체를 통해서만 접근이 가능합니다.
    Sample object;
    cout << object.a << endl;

    // 2. 정적 멤버 데이터는 클래스와 객체를 통해서 접근이 가능합니다.
    //  1) 클래스::
    cout << Sample::s << endl;

    //  2) 객체.
    cout << object.s << endl;

    // 3. 멤버 함수는 객체를 통해서만 호출이 가능합니다.
    object.foo();

    // 4. 정적 멤버 함수는 클래스와 객체를 통해서 호출이 가능합니다.
    //  1) 클래스::
    Sample::goo();

    //  2) 객체.
    object.goo();
}
#endif

class Sample {
    int a = 10; // 멤버 데이터
    static int s; // 정적 멤버 데이터

public:
    // * 멤버 함수는 첫번째 인자로 객체의 주소가 this를 통해
    //   전달됩니다.
    void foo() // void Sample::foo(Sample* this)
    {
        cout << this->a << endl;
        cout << this->s << endl;
    }

// * 정적 멤버 함수는 일반 함수와 동일하게, 객체의 주소가
//   암묵적으로 전달되지 않습니다.
#if 0
    static void goo()
    {
        // cout << a << endl;
        // this가 전달되지 않기 때문에 접근이 불가능합니다.

        // foo();
        // this가 없으므로, 멤버 함수도 호출이 불가능합니다.

        cout << s << endl;
    }
#endif
    // 정적 멤버 함수에 객체의 주소를 명시적으로 전달하면,
    // 객체의 주소를 통해 멤버 데이터에 접근하거나, 멤버 함수를 호출할 수 있습니다.
    static void goo(Sample* self)
    {
        cout << self->a << endl; // OK!
        self->foo(); // OK!
    }
};
int Sample::s = 100;

int main()
{
    Sample obj;
    obj.foo(); // Sample::foo(&obj)

    // Sample::goo();
    Sample::goo(&obj);
}
