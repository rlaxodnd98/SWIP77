// 31_연산자오버로딩7.cpp
#include <iostream>
using namespace std;

class Image {
public:
    Image() { cout << "Image()" << endl; }
    ~Image() { cout << "~Image()" << endl; }

    void Draw() const { cout << "Draw Image" << endl; }
};

// Image* 역활을 수행하는 클래스입니다.
// => 스마트 포인터
template <typename T>
class Ptr {
    T* obj;

public:
    inline Ptr(T* p = nullptr)
        : obj { p }
    {
    }

    inline ~Ptr() { delete obj; }

    inline T& operator*() { return *obj; }
    inline T* operator->() { return obj; }
};

#if 0
int main()
{
    // Ptr p = new Image;
    // Ptr<Image> p { new Image };
    // C++17, 클래스 템플릿도 생성자의 인자를 통해
    //        타입을 추론할 수 있습니다.
    Ptr p { new Image };

    (*p).Draw();
    //----------
    // (p.operator*()).Draw();

    p->Draw();
    // 실제: p.operator->()Draw();
    // 컴파일러가 처리하는 형태: p.operator->()->Draw()
}
#endif

#if 0
int main()
{
    Image* p = new Image;

    (*p).Draw();
    p->Draw();

    delete p;
}
#endif

// C++표준에서 이미 잘 만들어진 스마트 포인터를 제공합니다.
//  : 자원의 소유권(Ownership)
// 1) shared_ptr
//  : 참조 계수 기반
// 2) unique_ptr
//   : 복사 금지

#include <memory>

int main()
{
    shared_ptr<Image> p { new Image };
    p->Draw();
    (*p).Draw();

    shared_ptr other = p;

    unique_ptr<Image> p2 { new Image };
    p2->Draw();
    (*p2).Draw();

    cout << p2 << endl;

    unique_ptr<Image> other2 = std::move(p2);
    cout << other2 << endl;
    cout << p2 << endl;
}
