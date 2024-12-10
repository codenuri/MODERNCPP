#include <iostream>

int x = 0;

int  f1() { return x; } // x 가 아닌 x의 값 "0" 을 반환한것
int& f2() { return x; } // 값 "0" 이 아닌 x 자체(별명)을 반환 한것

int main()
{
	// 함수 반환값과 lvalue, rvalue 
	f1() = 20;	// "0 = 20" 의 의미. error
	f2() = 20;	// "x = 20" 의 의미. 따라서, ok

	// 함수가 참조(reference)를 반환하면 
	// => 함수 호출의 등호의 왼쪽에 놓을수 있다.
	
	// 그래서 C++ 에서는 "등호의 왼쪽" 에 오는 것을
	// => reference type 이라고 생각하게 됩니다.
	// => 그래서, decltype() 의 2번째 규칙이 정해진것. 
}
