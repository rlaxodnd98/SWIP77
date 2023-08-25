// stack.h
#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* buff;
    int top;

public:
    ~Stack();

    Stack(int size);
    Stack();

    inline void Push(int n);
    inline int Pop();
};

void Stack::Push(int n)
{
    buff[top++] = n;
}

int Stack::Pop()
{
    return buff[--top];
}

#endif
