#include <iostream>
#include <type_traits>

// enable_if ���
// => C++20 ������ ������ ���� �θ� ���Ǿ����ϴ�.
// => ��Ȯ�� ���� �ϸ� �׷��� ����� ����� �ƴմϴ�. (SFINAE �� �� Ȱ���Ѱ�)
// => �׷���, �ڵ尡 ������ ���Դϴ�.

// �׷���, C++20 ���� "requires clauses" ��� ������ ���Ե˴ϴ�.
// => enable_if ��� ��ũ���� "�������� ����" ��Ų��. 
// => �Ʒ� �ڵ� �����Ϸ��� "C++���� 20" ���� �����ؾ� �մϴ�.

template<typename T> requires std::is_pointer_v<T>
void printv(const T& v)
{
	std::cout << "�������� ���\n";
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v)
{
	std::cout << "�����Ͱ� �ƴ� ���\n";
	std::cout << v << std::endl;
}


int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}