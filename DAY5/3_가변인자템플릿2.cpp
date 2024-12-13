#include <iostream>

// 가변인자 함수 템플릿

// 인자가 한개인 함수 템플릿의 의미
// => 인자가 한개인 함수를 다양한 타입에 대해서 생성하겠다는 것
template<typename T> 
void goo(T arg)
{
}

// 가변 인자 함수 템플릿의 의미
// => 인자의 갯수에 상관없이. 이름이 foo 인 함수를 생성하겠다는 것
// => 이 분야를 학습 할때 "godbolt.org" 에서 직접 생성된 함수를 확인하는 것이
//    많은 도움이 됩니다.
template<typename ... Types> 
void foo(Types ... args)
{
}

int main()
{
	foo(1);			// foo(int) 생성
	foo(1, 3.4);	// foo(int, double) 생성
	foo(1, 3.4, 'A');
}
