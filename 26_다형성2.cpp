// 26_다형성2.cpp
#include <iostream>
using namespace std;

#if 0
class Dog {
public:
    int GetAge() const { return 10; }
};

class Cat {
public:
    int GetAge() const { return 10; }
};

void PrintAge(const Dog& a)
{
    cout << a.GetAge() << endl;
}

void PrintAge(const Cat& c)
{
    cout << c.GetAge() << endl;
}

int main()
{
    Dog d;
    PrintAge(d);

    Cat c;
    PrintAge(c);
}
#endif

class Animal {
public:
    int GetAge() const { return 10; }
};

class Dog : public Animal { };
class Cat : public Animal { };

// 1) 동종을 처리하는 함수를 만들 수 있습니다.
void PrintAge(const Animal& a)
{
    cout << a.GetAge() << endl;
}

int main()
{
    Dog d;
    PrintAge(d);

    Cat c;
    PrintAge(c);
}
