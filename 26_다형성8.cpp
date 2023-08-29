// 26_다형성8.cpp
#include <iostream>
#include <vector>
using namespace std;

// 1. 각 도형의 클래스를 설계합니다.

// 2. 부모 클래스
//   => 동종을 보관하는 컨테이너

// 3. 자식 클래스의 공통의 기능을 부모 클래스의 포인터/참조를 통해서
//    이용하기 위해서는 해당 특징인 부모로부터 비롯되어야 합니다.
//    그래야 해당 기능을 부모의 포인터(참조)를 통해서 이용할 수 있습니다.
//     : LSP(Liskov Substitution Pinciple, 리스코프 치환 원칙)
//      - 자식 클래스는 부모 클래스도 대체할 수 있어야 한다.
//         "자식의 공통의 기능이 부모로부터 비롯되어야 한다."

// 4. 자식이 재정의하는 모든 모든 멤버 함수는 반드시 가상 함수 이어야 한다.
// 5. 반드시 부모의 소멸자는 가상 이어야 합니다.

class Shape {
public:
    virtual ~Shape() { }

    virtual void Draw() const { cout << "Shape Draw" << endl; }
};

class Rect : public Shape {
public:
    void Draw() const override { cout << "Rect Draw" << endl; }
};

class Circle : public Shape {
public:
    void Draw() const override { cout << "Circle Draw" << endl; }
};

int main()
{
    vector<Shape*> shapes;

    while (1) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            shapes.push_back(new Rect);
        } else if (cmd == 2) {
            shapes.push_back(new Circle);
        } else if (cmd == 9) {

            for (auto e : shapes) {
                e->Draw();
            }
        } else if (cmd == 0) {
            break;
        }
    }

    for (auto e : shapes) {
        delete e;
    }
}
