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

// 3) using 지시어(directive)
// => 특정 이름 공간에 존재하는 모든 것을
//    암묵적으로 접근할 수 있습니다.

namespace audio {
namespace mp3 {
    void Play() { }
}
}

using namespace audio::mp3;
using namespace std;

int main()
{
    Play();

    cout << "Hello, C++" << endl;
}
