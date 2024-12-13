#include <iostream>

// recursive 유사 기술

// 1. 모든 인자를 "가변인자"로 하지 말고, 1번째 인자는 독립된 이름으로 받는다.

void foo() {}	// 재귀 종료를 위해서 인자 없는 foo - C++11

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value << std::endl;

	foo(args...); // foo(3.4, 'A')	=> value : 3.4,    args : 'A'
				  // foo('A')		=> value : 'A'     args : 
				  // foo() => 재귀 종료를 위해 인자 없는 foo 도 필요		
}

int main()
{
	foo(1, 3.4, 'A');	// value : 1,   args : 3.4,  'A'
}





