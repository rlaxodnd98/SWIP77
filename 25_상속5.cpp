// 25_상속5.cpp
#include <iostream>
#include <string>
using namespace std;

#if 0
class Student {
    string name_;
    int age_;
    int score_;

public:
    Student(const string& name, int age, int score)
        : name_ { name }
        , age_ { age }
        , score_ { score }
    {
    }
};

class Teacher {
    string name_;
    int age_;
    string major_;

public:
    Teacher(const string& name, int age, const string& major)
        : name_ { name }
        , age_ { age }
        , major_ { major }
    {
    }
};

int main()
{
    Student s { "Tom", 42, 100 };
    Teacher t { "Bob", 55, "Math" };
}
#endif

class User {
    string name_;
    int age_;

public:
    User(const string& name, int age)
        : name_ { name }
        , age_ { age }
    {
    }
};

class Student : public User {
    int score_;

public:
    Student(const string& name, int age, int score)
        : User { name, age }
        , score_ { score }
    {
    }
};

class Teacher : public User {
    string major_;

public:
    Teacher(const string& name, int age, const string& major)
        : User { name, age }
        , major_ { major }
    {
    }
};

int main()
{
    Student s { "Tom", 42, 100 };
    Teacher t { "Bob", 55, "Math" };
}
