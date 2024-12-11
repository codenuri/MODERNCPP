#include <iostream>

// 평가 할때 이 소스 참고하시면 됩니다.

template<typename T> void foo(T&& arg)
{
	// 확인하는법
	// 1. godbolt.org 에서 생성된 어셈블리 확인 - 가장 권장..!!
	// 2. 생성된 함수 이름을 출력
	//    g++ : __PRETTY_FUNCTION__
	//    vs  : __FUNCSIG__

	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 10;

	foo(n);  //	T = int&,  T&& = int& && => int&,  foo(int& arg)
	foo(10); // T = int,   T&& = int&&             foo(int&& arg)
}




