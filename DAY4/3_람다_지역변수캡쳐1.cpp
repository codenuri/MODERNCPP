// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// #1. 람다표현식에서 전역변수
	// => 접근 가능하고, R/W 모두 가능.
	auto f1 = [](int a) { g = 10;  return a + g; }; // ok
			  // class xxx{ operator()(int a) const  { g = 10; return a + g; }}; xxx{}; 


	// #2. 람다 표현식에서 main 함수의 지역변수 접근
	auto f1 = []	  (int a) { return a + v1 + v2; };	// error. 
	auto f2 = [v1, v2](int a) { return a + v1 + v2; };	// ok. 
	auto f3 = [v1, v2](int a) { v1 = a; v2 = a; };		// error
	auto f4 = [v1, v2](int a) mutable { v1 = a; v2 = a; };	// ok
}





