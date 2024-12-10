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
	// decltype(expression) �� Ư¡
	// => expression �� ����� �������� �Ӽ�(Ÿ��, value) �����Ҽ� �ֽ��ϴ�.
	// => ��Ģ #2.  expression �� ���ʿ� �ü� �ִٸ� ���� Ÿ��

	int n = 10;


	// expression �� lvalue ���� rvalue ������ �����ϴ� ���
	// => decltype(expression) �� ����� ���� Ÿ������ �����ϸ� �˴ϴ�.
	// => () �ȿ� id-expression �� ���� ��Ģ#1 �� �ƴ� ��Ģ #2�� ����ϰ�
	//    �ϱ� ���ؼ� ()�� �Ѱ� �� �ִ� ���� �ٽ�.
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