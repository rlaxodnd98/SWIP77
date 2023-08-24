#ifndef CALC_H
#define CALC_H

// C/C++ 동시에 사용할 수 있도록 만들어진 헤더 파일
#ifdef __cplusplus
extern "C" int add(int a, int b);
#else
int add(int a, int b);
#endif

#endif
