#include <iostream>

// SFINAE

// 아래 예제에서는 함수 찾는 순서 알아 두세요
// => 더 자세히 알고 싶다면 "overloading resolution" 검색해 보세요
// 
//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }

// void foo(int a) { std::cout << "int" << std::endl; }

void foo(...)   { std::cout << "..." << std::endl; }

int main()
{
	foo(3); // 1. foo(int) 호출 - exactly matching
			// 2. foo(T) 를 사용해서 int 버전 생성
			// 3. foo(...) 호출	
}




