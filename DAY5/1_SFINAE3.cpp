#include <iostream>
#include <type_traits>

void foo(...) { std::cout << "..." << std::endl; }

/*
template<typename T>
void foo(T n)
{
	typename T::type n;	// SFINAE �� ����ɱ�� ?
						// ���� �Դϴ�. SFINAE ����ȵ˴ϴ�.
}
*/
// SFINAE �� �Լ��� signature ������ ����˴ϴ�.
// => �Լ� ��ȯ Ÿ��, ���� Ÿ��, template ���� Ÿ��
// #1. �Լ� ��ȯ Ÿ��
// template<typename T>
//typename T::type foo(T n) { return 0; }


// #2. �Լ� ����
// template<typename T>
// void foo(T n, typename T::type a = 0 ) {  }


// #3. ���ø� ����
template<typename T, typename T2 = typename T::type >
void foo(T n) {}

// ��κ� SFINAE �� Ȱ���ϴ� ����
// => ��ȯ Ÿ�Կ� ����ϴ� ��찡 �����ϴ�
// => enable_if ���� ����.. 

int main()
{
	foo(0);
}