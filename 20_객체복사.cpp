// 20_객체복사.cpp
#include <iostream>
using namespace std;

class User {
    char* name;
    int age;

public:
    User(const char* s, int n)
        : age { n }
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    void Print()
    {
        cout << name << "(" << age << ")" << endl;
    }
};

int main()
{
    User user { "Tom", 42 };
    user.Print();
}
