#include <iostream>

// 90 page

// reference 와 함수 오버로딩
// => 아래 처럼 오버로딩 가능합니다.

void foo(int& a)       { std::cout << "1. int&" << std::endl; }		
void foo(const int& a) { std::cout << "2. const int&" << std::endl; }
void foo(int&& a)      { std::cout << "3. int&&" << std::endl; }

int main()
{
	int n = 10;

	foo(n);		// 1. (1) int& 버전 호출.
				// 2. (1) 이 없다면 (2)번 호출.
	
	foo(10);	// 1. (3) int&& 버전 호출
				// 2. (3) 이 없다면 (2)번 호출

	// 위 규칙도 아주 중요합니다.
	// 반드시 외워 두세요

}







