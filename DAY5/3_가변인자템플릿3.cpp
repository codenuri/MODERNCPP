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

	
	// #3. pack 안에 있는 요소에 접근하는 방법
	// 1. pack expansion     - C++11. 가장 널리 사용하는 일반적인 방법
	// 2. recursive 유사 코드 - C++11
	// 3. fold expression    - C++17
	// 4. pack indexing      - C++26 부터.

	// pack indexing : []를 사용해서 pack 안의 요소 접근(배열과 유사)
	// 현재는 visual studio, g++ 모두 지원 안됩니다.
	// clang++ 의 다음 버전(19) 부터 지원할 예정
//	auto  n = args...[0]; // 1
//	using T = Types...[0]; // using T = int


}


int main()
{
	foo(1, 2, 3);
}
