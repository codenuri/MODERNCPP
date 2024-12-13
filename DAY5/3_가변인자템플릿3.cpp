#include <iostream>

template<typename ... Types> void foo(Types ... args)
{
	// 컴파일러가 생성한 함수
	// void foo(int arg1, int arg2, int arg3)

	// #1. parameter pack 이라는 용어 알아 두세요
	// Types : int, int, int	<= template parameter pack
	// args  : 1, 2, 3			<= function parameter pack

	// #2. pack 안에 요소의 갯수를 확인하는 방법
	std::cout << sizeof...(Types) << std::endl; // 3
 	std::cout << sizeof...(args)  << std::endl; // 3
}


int main()
{
	foo(1, 2, 3);
}
