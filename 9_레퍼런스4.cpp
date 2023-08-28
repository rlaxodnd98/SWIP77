#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }
};

int main()
{
    cout << "-----" << endl;
    // Sample&& r = Sample();
    Sample();
    cout << "-----" << endl;
    // 임시 객체는 레퍼런스에 의해 참조되면, 레퍼런스의 수명과 동일해집니다.
}

#if 0
int main()
{
    Sample s; // lvalue
    Sample& r1 = s;

    Sample&& r2 = Sample(); // 임시 객체는 rvalue 입니다.
}
#endif
