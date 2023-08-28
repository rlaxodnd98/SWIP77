// 19_복사생성자3.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    Sample(const Sample&) { cout << "Sample(const Sample&)" << endl; }

    ~Sample() { cout << "~Sample()" << endl; }
};

Sample s; // Sample()

// 2) 함수가 객체를 값으로 반환할 때

// 지역 객체는 함수가 끝나면 사라지기 때문에,
// 참조로 반환하는 것은 미정의 동작이 발생합니다.
// 유지되는 메모리(전역 객체, 멤버 객체)는 함수가 끝나도 유효하므로,
// 참조로 반환하면, 불필요한 반환용 임시 객체의 복사 생성 비용과 소멸 비용을
// 최적화할 수 있습니다.
// Sample foo()
Sample& foo()
{

    return s;
    // 객체를 함수에서 값으로 반환할 때,
    // 반환용 임시객체가 생성됩니다.
    //  => Sample(const Sample&)
}

int main()
{
    cout << "-------" << endl;
    foo();
    // 반환용 임시 객체 소멸자 호출
    //  => ~Sample()
    cout << "-------" << endl;
}
