// 25_상속.cpp
#include <iostream>
#include <string>
using namespace std;

// 상속
// : 각 클래스가 제공하는 공통의 기능을 부모 클래스로 캡슐화할 수 있습니다.

#if 0
class Student {
    string name;
    int age;
    int score;

public:
    string GetName() const { return name; }
    int GetAge() const { return age; }
    int GetScore() const { return score; }
};

class Teacher {
    string name;
    int age;
    int major;

public:
    string GetName() const { return name; }
    int GetAge() const { return age; }
    int GetMajor() const { return major; }
};

int main()
{
    Student s;
    Teacher t;

    s.GetAge();
    t.GetAge();

    s.GetName();
    t.GetName();

    s.GetScore();
    t.GetMajor();
}
#endif

// 공통의 속성을 캡슐화한 부모 클래스
class Person {
    string name;
    int age;

public:
    string GetName() const { return name; }
    int GetAge() const { return age; }
};

class Student : public Person {
    int score;

public:
    int GetScore() const { return score; }
};

class Teacher : public Person {
    int major;

public:
    int GetMajor() const { return major; }
};

int main()
{
    Student s;
    Teacher t;

    s.GetAge();
    t.GetAge();

    s.GetName();
    t.GetName();

    s.GetScore();
    t.GetMajor();
}
