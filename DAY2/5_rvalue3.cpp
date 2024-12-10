// 5_rvalue3.cpp
#include <iostream>
#include <type_traits>

int main()
{
	// decltype(expression) 의 특징
	// => expression 이 만드는 최종값에 속성(타입, value) 조사할수 있습니다.
	// => 규칙 #2.  expression 이 왼쪽에 올수 있다면 참조 타입

	int n = 10;

	if ( std::is_lvalue_reference_v< decltype(n * 2) > )
	{
		std::cout << "lvalue\n";
	}
	else 
		std::cout << "rvalue\n";
}