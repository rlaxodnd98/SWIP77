

class Sample {
};

int main()
{
    Sample s; // lvalue
    Sample& r1 = s;

    Sample&& r2 = Sample(); // 임시 객체는 rvalue 입니다.
}
