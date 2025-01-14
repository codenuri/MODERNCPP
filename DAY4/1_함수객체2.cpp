﻿#include <iostream>

// 함수객체와 const member function
// => 함수객체 만들때 operator() 는 "const member function" 으로 하는 것이 원칙 입니다.
// => 단, operator() 에서 멤버 변수를 수정하는 코드가 있다면, 예외..
// => 이 사실이, "람다 표현식" 에서 중요하게 등장합니다.!! 꼭 알아 두세요.. 

struct Plus
{
	
	int operator()(int a, int b) const 
	{
		return a + b;
	}
};

// 함수 객체를 함수 인자로 받는 경우
// 함수 객체는 일반적으로 "멤버 데이타"가 없는 경우가 많습니다.
// => empty class, sizeof(emptyclass) => 1바이트 
// => 크기가 작으므로 "call by value" 로 받는 것이 일반적인 코드..
// template<typename T> void foo(T f)

// 하지만, 경우 따라, 함수객체가 많은 멤버 데이타가 있을수 있습니다.
template<typename T> void foo(const T& f)
{
	int ret = f(1, 2);	// f.operator()(1, 2) 의 형태 인데
						// f가 상수 객체 입니다.
						// 따라서, 이코드가 컴파일 되려면
						// operator()(1,2) 함수가 const 멤버 함수 이어야 합니다.
}

int main()
{
	Plus p;

	foo(p);
}



