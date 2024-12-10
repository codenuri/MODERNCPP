// 5_rvalue3.cpp
#include <iostream>
#include <type_traits>

#define VALUE_CATEGORY( ... )									\
if (std::is_lvalue_reference_v< decltype(( __VA_ARGS__  )) >)	\
{																\
	std::cout << "lvalue\n";									\
}																\
else                                                            \
{																\
	std::cout << "rvalue\n";									\
}


int main()
{
	// decltype(expression) 의 특징
	// => expression 이 만드는 최종값에 속성(타입, value) 조사할수 있습니다.
	// => 규칙 #2.  expression 이 왼쪽에 올수 있다면 참조 타입

	int n = 10;


	// expression 이 lvalue 인지 rvalue 인지를 조사하는 방법
	// => decltype(expression) 의 결과가 참조 타입인지 조사하면 됩니다.
	// => () 안에 id-expression 인 경우라도 규칙#1 이 아닌 규칙 #2를 사용하게
	//    하기 위해서 ()를 한개 더 넣는 것이 핵심.
	/*
	if ( std::is_lvalue_reference_v< decltype( ( n ) ) > )
	{
		std::cout << "lvalue\n";
	}
	else 
		std::cout << "rvalue\n";

	*/
	VALUE_CATEGORY(n);
	VALUE_CATEGORY(n+n);
	VALUE_CATEGORY(++n);
	VALUE_CATEGORY(n--);
}