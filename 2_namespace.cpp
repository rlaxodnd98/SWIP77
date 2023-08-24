// 2_namespace.cpp
#include <iostream>

// 1. C는 이름 충돌 문제를 해결할 수 있는 문법이 없습니다.
//  => 다른 이름을 약속합니다.

// 2. C++은 이름 충돌의 문제를 해결하기 위해서,
//    namespace 문법을 지원합니다.
#if 0
namespace audio {
void Init() { std::cout << "Audio Init" << std::endl; }

int global = 100;
}

namespace video {
void Init() { std::cout << "Video Init" << std::endl; }

int global = 100;
}

int main()
{
    std::cout << "Hello, C++" << std::endl;
}
#endif

// 3. namespace를 사용하면 프로그램의 각 요소를
//    관련된 요소끼리 그룹화할 수 있습니다.
#if 0
namespace video {
namespace mp3 {
    void Play() { }
}

namespace mp4 {
    void Play() { }
}
}

// 4. C++ 표준의 모든 요소는 std 이름 공간안에 약속되어 있습니다.
int main()
{
    video::mp3::Play();
    video::mp4::Play();

    std::cout << "Hello, C++" << std::endl;
}
#endif

// #include <stdio.h>
// 5) C++에서는 C의 헤더를 사용할 때,
//    stdio.h  -> cstdio
//    stdlib.h -> cstdlib
//    string.h -> cstring
//    위의 형태로 사용하는 것이 좋습니다.
#include <cstdio>

int main()
{
    std::printf("Hello, C++\n");
}
