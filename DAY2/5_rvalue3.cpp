// 5_rvalue3.cpp
#include <iostream>
#include <type_traits>

int main()
{
	// decltype(expression) �� Ư¡
	// => expression �� ����� �������� �Ӽ�(Ÿ��, value) �����Ҽ� �ֽ��ϴ�.
	// => ��Ģ #2.  expression �� ���ʿ� �ü� �ִٸ� ���� Ÿ��

	int n = 10;

	if ( std::is_lvalue_reference_v< decltype(n * 2) > )
	{
		std::cout << "lvalue\n";
	}
	else 
		std::cout << "rvalue\n";
}