// 26_다형성3.cpp
#include <iostream>
#include <vector> // 컨테이너
using namespace std;

#if 0
class Dog { };
class Cat { };

int main()
{
    vector<Dog*> dogs;
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);
    // dogs.push_back(new Cat);

    vector<Cat*> cats;
    cats.push_back(new Cat);
    cats.push_back(new Cat);
    cats.push_back(new Cat);
}
#endif

// 2) 동종을 보관하는 컨테이너
class Animal { };
class Dog : public Animal { };
class Cat : public Animal { };

int main()
{
    vector<Animal*> animals;

    animals.push_back(new Dog);
    animals.push_back(new Cat);
    animals.push_back(new Dog);
    animals.push_back(new Cat);
    animals.push_back(new Dog);
    animals.push_back(new Cat);
}
