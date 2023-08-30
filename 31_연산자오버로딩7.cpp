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

#if 1
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
