// 17_this2.cpp
#include <iostream>
using namespace std;

// private 소멸자
//  : "객체 생성을 new를 통해서만 허용하겠다" 의도
// => 객체를 파괴하기 위한 멤버 함수를 제공해야 합니다.

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }

#if 0
    void Destroy(Sample* p)
    {
        delete p;
    }
#endif
    void Destroy() // void Sample::Destory(Sample* this)
    {
        delete this;
    }

private:
    ~Sample() { cout << "~Sample()" << endl; }
};

int main()
{
    Sample* s = new Sample;

    // delete s;
    // s->Destroy(s);

    s->Destroy();
    // Sample::Destory(s);
}

#if 0
Sample s;
int main()
{
    // Sample s; // Sample::Sample()
} // Sample::~Sample()
#endif
