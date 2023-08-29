// 27_추상클래스4.cpp
#include <iostream>
using namespace std;

// 인터페이스의 문제점
// : 인터페이스에 새로운 기능을 추가하기 어렵습니다.
//   인터페이스에 새로운 기능이 추가되면, 기존에 인터페이스를 구현하는 모든
//   클래스가 해당 기능을 제공해야 합니다.
//   제공하지 않는다면, 추상 클래스가되서 객체를 생성할 수 없습니다.

// * 인터페이스의 정의가 변경되었습니다.
//  => 현대적인 객체지향 설계에서는 인터페이스에 기분 구현을 제공하는 것이
//     가능합니다.

class MP3 {
public:
    virtual ~MP3() { }

    virtual void Play() = 0;
    virtual void Stop() = 0;

    // 인터페이스에 새로운 기능을 추가할 때, 기본 구현을 제공하는 것이
    // 좋습니다.
    //  => Java 8: defender method
    virtual void PlayOneMinute()
    {
        // ...
    }
};

class Car {
    MP3* mp3;

public:
    Car(MP3* p)
        : mp3 { p }
    {
    }

    void PlayMusic()
    {
        mp3->Play();
        mp3->Stop();

        mp3->PlayOneMinute();
    }
};

class Player : public MP3 {
public:
    void Play() override { }
    void Stop() override { }
};

class Player2 : public MP3 {
public:
    void Play() override { }
    void Stop() override { }
};

int main()
{
    // Player mp3;
    Player2 mp3;
    Car car { &mp3 };

    car.PlayMusic();
}
