// 17_this3.cpp
#include <iostream>
#include <string>
using namespace std;

class Image {
    string url;
    int ref;

private:
    ~Image() { cout << "~Image()" << endl; }
    // Image 객체는 오직 new를 통해서만 생성할 수 있습니다.

public:
    Image(const string& s)
        : url { s }
        , ref { 1 }
    {
    }

    void AddRef() { ++ref; }
    void Release()
    {
        if (--ref == 0) {
            delete this;
        }
    }

    void Draw() const
    {
        cout << "Draw Image: " << url << endl;
    }
};

int main()
{
    Image* p1 = new Image { "https://a.com/1.jpg" }; // Ref: 1

    Image* p2 = p1;
    p2->AddRef(); // Ref: 2

    p1->Release(); // Ref: 1
    p2->Release(); // Ref: 0
}
