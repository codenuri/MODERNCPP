#include <iostream>

// #1. 함수는 자신만의 타입이 없다.
//     signature(리턴 타입과 인자 모양)가 동일한 함수는 모두 같은 타입이다.

// #2. 함수객체는 자신만의 타입이 있다.
//     signature(리턴 타입과 인자 모양)가 동일해도 모든 함수 객체는 다른 타입이다.

struct Less    { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

//-------------------------------
// 아래 코드는 "비교 정책 을 교체" 할수 있고
// 비교 정책 함수가 "인라인 치환"도 가능합니다.
// => 함수 객체와 template 으로 만드는 기술
// => STL 의 핵심 설계 원리 입니다.

template<typename T>
void Sort(int* x, int sz, T cmp )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (cmp(x[i], x[j]) == false)	
				std::swap(x[i], x[j]);
		}
	}
}

int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(5, 3); Sort(x, 10, f1); // ok
	Greater f2; f2(5, 3); Sort(x, 10, f2); // ??
}