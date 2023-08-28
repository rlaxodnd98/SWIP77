// 19_복사생성자2.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    Sample(const Sample&) { cout << "Sample(const Sample&)" << endl; }

    ~Sample() { cout << "~Sample()" << endl; }
};

// 복사 생성자가 호출되는 경우
// 1) 객체가 함수로 call by value로 전달될 때
//  : C++에서는 객체를 함수의 인자로 전달할 때,
//    call by value대신 const&를 사용합니다.
//   "불필요한 복사 생성/소멸 비용의 제거를 위해서"

void foo(const Sample& s) // - Sample(const Sample&)
{
} // ~Sample()

int main()
{
    Sample s; // Sample()
    cout << "--------" << endl;
    foo(s);
    cout << "--------" << endl;
}
