// 2_namespace2.cpp
#include <iostream>

// namespace를 사용하는 3가지 방법
// 1) 전체 이름을 명시하는 방법
#if 0
namespace audio {
namespace mp3 {
    void Play() { }
}
}

int main()
{
    audio::mp3::Play();

    std::cout << "Hello, C++" << std::endl;
}
#endif

// 2) using 선언(declaration)
#if 0
namespace audio {
namespace mp3 {
    void Play() { }
}
}

using audio::mp3::Play;
using std::cout;
using std::endl;

int main()
{
    Play();

    cout << "Hello, C++" << endl;
}
#endif

#if 0
// 3) using 지시어(directive)
// => 특정 이름 공간에 존재하는 모든 것을
//    암묵적으로 접근할 수 있습니다.
// : 이름 충돌의 문제가 발생합니다.
// - 현업에서 절대 사용하지 않는 것이 좋습니다.
namespace audio {
namespace mp3 {
    void Play() { }
}

void foo() { }

}

namespace video {
void Play() { }
}

using namespace audio::mp3;
using namespace std;
using namespace video;

int main()
{
    Play();

    cout << "Hello, C++" << endl;
}
#endif

#include <iostream>
// using namespace std;
// using std::count;
using std::cout;
using std::endl;

int count = 100;

namespace audio {
int count = 0;

// void Play() { ++count; }
// - 같은 이름 공간의 요소를 암묵적으로 접근합니다.

void Play() { ++::count; }
// C++에서는 전역 공간을 명시적으로 접근할 수 있습니다.
}

int main()
{

    // cout << count << endl;
    // 표준 라이브러리 안에 count 이름의 함수가 존재합니다.
    // 이름 충돌로 인해서, 컴파일러는 어떤 count를 선택할지
    // 알 수 없습니다.
}
