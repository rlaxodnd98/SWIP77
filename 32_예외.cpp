// 32_예외.cpp
#include <iostream>
using namespace std;

#include <cstdlib>

// 1. 반환값을 통해서 함수의 성공/실패를 전달하는 경우가 많습니다.
// 2. 반환값을 통한 오류 처리의 문제점
//  1) 연산의 결과가 오류인지 결과인지 구분하기 모호할 수 있습니다.
//     atoi
//    => strtol
//     원인: 결과를 전달할 때, return
//          오류를 전달할 때, return
//  2) 실패 가능한 함수는 반드시 오류 체크를 해야합니다.
//    => 오류 처리를 강제할 수 없습니다.

//  3. 예외
// 1) 결과는 return 하고,
//    오류는 throw 합니다.
// 2) 함수를 수행하였을 때, throw한 오류를 처리(catch)하지 않으면,
//    실행시간에 비정상 종료됩니다.

#if 0
int OpenFile(const char* filename)
{
    if (filename == nullptr) {
        return -1;
    }

    return 0;
}
#endif

int OpenFile(const char* filename)
{
    if (filename == nullptr) {
        throw -1;
        // 오류를 throw 합니다.
    }

    return 0;
}

int main()
{
    // int result = OpenFile("a.txt");
    try {
        int result = OpenFile(nullptr);
        cout << result << endl;
    } catch (int& r) {
        cout << r << endl;
    }
}

#if 0
int Calculate(int a, int b)
{
    // 함수가 실패할 경우, -1을 반환합니다.
    return -1;
}

int main()
{
    int result = atoi("0");
    cout << result << endl;
}
#endif
