// 8_제어문.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int x[5] = { 1, 2, 3, 4, 5 };

    // size_t len = sizeof(x) / sizeof(int);
    constexpr size_t len = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < len; i++) {
        cout << x[i] << endl;
    }

    // C++11, Ranged-for
    for (auto e : x) {
        cout << e << endl;
    }
}
#endif

struct File {
    int n;
};

File* OpenFile(const char* filename)
{
    // 실패할 경우, NULL을 반환합니다.
    return NULL;
}

int Process()
{
    // 실패할 경우, 0이 아닌 값을 반환합니다.
    return -1;
}

// C/C++ 에서 실패 가능성이 존재하는 모든 함수는
// 반드시 반환값을 통해 함수의 성공 실패 여부를 체크해야합니다.
#if 0
int main()
{
    File* ret = OpenFile("a.txt");
    if (ret == NULL) {
        // ...
    }

    int ret2 = Process();
    if (ret2 != 0) {
        // ...
    }
}
#endif

enum TaskState {
    TASK_RUNNING,
    TASK_STOPPED
};

TaskState GetTaskState()
{
    return TaskState::TASK_STOPPED;
}

// If/Switch-statement with Initializaer, C++17
int main()
{
    // 조건문에서만 유효한 변수를 정의할 수 있습니다.
    if (File* ret = OpenFile("a.txt"); ret == NULL) {
        // ...
    }

    if (int ret = Process(); ret != 0) {
        // ...
    }

    switch (TaskState state = GetTaskState(); state) {
    case TaskState::TASK_RUNNING:
        // state
        break;
    case TaskState::TASK_STOPPED:
        break;
    }
}
