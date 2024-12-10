#include <iostream>

// 추론된 타입을 확인하는 방법
// #1. godbolt.org 사용 => 가장 권장!!
// #2. 생성된 함수의 이름을 출력 => 역시 좋은 방법
// #3. RTTI 기술 사용 => 버그 있음. 사용하지 말것  

template<typename T> void foo(T a)
{
	// __func__ : 함수 이름을 담은 매크로 (C++표준)
	//			  인자 없이 함수 이름만..

	// __FUNCSIG__ : 함수 이름 + 함수 인자 (C++ 표준아님. MS 컴파일러만 지원)
	// __PRETTY_FUNCTION__ : g++, clang++ 만 지원

	//std::cout << __func__ << std::endl;
	std::cout << __FUNCSIG__ << std::endl;
	
}

int main()
{

	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);	// T = int
	foo(c); // T = int
	foo(r); // T = int
	foo(cr);// T = int 
}
