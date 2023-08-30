// stack2.h
// ODR: One Definition Rule

// #pragma once
// 표준이 아닙니다.

#ifndef STACK2_H_
#define STACK2_H_

class Stack {
public:
    inline void Push();
};

// Stack.cpp

// 인라인 함수는 반드시 헤더를 통해
// 제공되어야 합니다.
void Stack::Push()
{
}

#endif
