// 33_STL.cpp
#include <iostream>
using namespace std;

// STL(Standard Template Library)
// - 1998: C++1차 표준안, STL 탄생

// STL 구성 요소 3가지
// 1) 컨테이너: 데이터를 보관하기 위한 자료구조
//  vector: 연속된 메모리의 동적 배열 / 선형 자료 구조
//    list: 노드 기반의 선형 자료 구조
//   deque: vector와 list의 중간 형태의 선형 자료 구조
//   map, set, unordered_map, unordered_set ...
//   stack, queue

// 2) 알고리즘: 컨테이너의 요소를 검색/정렬/이진 탐색 연산등을 제공하는
//            "일반 함수"

// 3) 반복자(Iterator): 컨테이너의 요소를 참조하는 타입

#include <vector>
#include <list>
#include <deque>

// * 컨테이너
// 1) 템플릿 기반입니다.
//  - 타입에 상관없이 다양한 자료구조를 사용할 수 있습니다.

// 2) 멤버 함수의 이름이 유사합니다.
//  => 자료 구조의 전환을 쉽게 수행할 수 있습니다.

// 3) 데이터를 참조하는 연산과, 제거하는 연산이 분리되어 있습니다.
//  => 값이 아니라 요소의 참조를 반환할 수 있습니다.

//             |--------------|
// 삽입:  push_front          push_back
// 제거:  pop_front           pop_back
// 참조:  front               back

#if 0
int main()
{
    // vector<int> v = { 10, 20, 30 };
    // deque<int> v = { 10, 20, 30 };
    list<int> v = { 10, 20, 30 };

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << v.back() << endl;
    v.pop_back();

    // list<int> l;
    // deque<int> d;
}
#endif

// vector
// 장점: 임의 접근이 가능합니다.
// 단점: 데이터의 삽입이 비효율적입니다.

// list
// 장점: 데이터의 삽입이 용이합니다.
// 단점: 임의 접근이 불가능합니다.

int main()
{
    vector<int> v = { 10, 20, 30 };
    cout << v[0] << endl; // 임의 접근 연산이 가능합니다.

    // v.push_front(100);
    // : 데이터를 앞에 삽입하는 연산이 제공되지 않습니다.

    list<int> l = { 10, 20, 30 };
    // cout << l[2] << endl; - 오류!
    //  : 임의 접근 연산을 list에서는 사용할 수 없습니다.

    l.push_front(10);
    // : 데이터를 앞에 삽입할 수 있습니다.
}
