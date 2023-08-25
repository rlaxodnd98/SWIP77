// 4_변수.cpp
#include <iostream>
using namespace std;

#if 0
// 사용자 정의 타입
// 1) struct
// 2) union
// 3) enum
struct complex {
    // -------
    //  구조체 태그

    int re;
    int im;
};
typedef struct complex COMPLEX;

union data {
    int i32;
    long long i64;
};
typedef union data DATA;

enum task_state {
    TASK_RUNNING,
    TASK_STOPPED,
};
typedef enum task_state TASK_STATE;

int main()
{
    // struct complex c1;
    COMPLEX c1;
    // union data d1;
    DATA d1;
    // enum task_state s1;
    task_state s1;
}
#endif

// * C++에서는 태그가 타입입니다.
struct Complex {
    int re;
    int im;
};

union Data {
    int i32;
    long long i64;
};

enum TaskState {
    TASK_RUNNING,
    TASK_STOPPED,
};

// C에서 typedef를 통해 제공하는 것이 더이상 필요하지 않습니다.
int main()
{
    Complex c1;
    Data d1;
    TaskState s1;
}
