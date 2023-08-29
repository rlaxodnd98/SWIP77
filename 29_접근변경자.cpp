// 29_접근변경자.cpp
#include <iostream>
#include <string>
using namespace std;

class Base {
private:
    string name;
    int age;

protected:
    string GetName() const { return name; }

public:
    int GetAge() const { return age; }
};

// class User : public Base {
//              ------
//             접근 변경자

//   <부모>     public 상속   <자식>
// protected   ---------->  protected
// public      ---------->  public

//   <부모>     protected 상속   <자식>
// protected   ---------->  protected
// public      ---------->  protected

//   <부모>     private 상속   <자식>
// protected   ---------->  private
// public      ---------->  private

// protected 상속과 private 상속은 부모와 자식간의 is-a 관계가
// 성립되지 않습니다.
//  : Upcasting이 불가능합니다.

class User : private Base {
};

int main()
{
    User user;
    user.GetName();
    user.GetAge();
}
