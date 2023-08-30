// 32_예외2.cpp
#include <iostream>
using namespace std;

// 예외의 종류에 따라서, 예외의 타입을 제공합니다.
#if 0
class InvalidFilenameException { };
class OutOfMemoryException { };

int OpenFile(const char* filename)
{
    if (filename == nullptr) {
        // throw -1;
        throw InvalidFilenameException();
        // 임시 객체를 던지는 형태로 사용합니다.
    }

    throw OutOfMemoryException();

    return 0;
}

int main()
{
    try {
        OpenFile(nullptr);
    } catch (InvalidFilenameException& e) {
        cout << "잘못된 파일명입니다." << endl;
    } catch (OutOfMemoryException& e) {
        cout << "메모리가 부족합니다." << endl;
    }
}
#endif

class InvalidFilenameException : public std::exception {
public:
    const char* what() const noexcept override
    {
        return "오류 메세지";
    }
};

class OutOfMemoryException : public std::exception { };

int OpenFile(const char* filename)
{
    if (filename == nullptr) {
        // throw -1;
        throw InvalidFilenameException();
        // 임시 객체를 던지는 형태로 사용합니다.
    }

    throw OutOfMemoryException();

    return 0;
}

int main()
{
    try {
        OpenFile(nullptr);
    } catch (InvalidFilenameException& e) {
        cout << "잘못된 파일명입니다." << endl;
    } catch (OutOfMemoryException& e) {
        cout << "메모리가 부족합니다." << endl;
    }

    try {
        OpenFile(nullptr);
    } catch (std::exception& e) {
        cout << e.what() << endl;
    }
}
