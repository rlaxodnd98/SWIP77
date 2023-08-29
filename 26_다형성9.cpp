// 26_다형성9.cpp
#include <iostream>
#include <vector>
using namespace std;

// * 리팩토링(Recfactoring), 마틴 파울러
//  정의: 코드의 기능을 변경하지 않고, 구조를 개선하는 작업
//   코드의 유지보수성을 떨어뜨리는 요소 => 냄새

// * Replace type code with polymorphism

class Shape {
public:
    virtual ~Shape() { }

    virtual Shape* Clone() const = 0;
    virtual void Draw() const = 0;
};

class Rect : public Shape {
public:
    Shape* Clone() const override
    {
        return new Rect(*this);
    }

    void Draw() const override { cout << "Rect Draw" << endl; }
};

class Circle : public Shape {
public:
    Shape* Clone() const override
    {
        return new Circle(*this);
    }

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
        } else if (cmd == 8) {
            cout << "몇번째 도형? ";
            int index;
            cin >> index;

            Shape* copy = shapes[index]->Clone();
            shapes.push_back(copy);

            // 문제점: 새로운 도형이 추가될 때마다, 아래 코드는 수정되어야 한다.
            /*
            if (shapes[index]->type == 0) { // Rect
            } else if (shapes[index]->type == 1) { // Circle
            }
            */

        }

        else if (cmd == 9) {

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
