#include <iostream>

// �߷е� Ÿ���� Ȯ���ϴ� ���
// #1. godbolt.org ��� => ���� ����!!
// #2. ������ �Լ��� �̸��� ��� => ���� ���� ���
// #3. RTTI ��� ��� => ���� ����. ������� ����  

template<typename T> void foo(T a)
{
	// __func__ : �Լ� �̸��� ���� ��ũ�� (C++ǥ��)
	//			  ���� ���� �Լ� �̸���..

	// __FUNCSIG__ : �Լ� �̸� + �Լ� ���� (C++ ǥ�ؾƴ�. MS �����Ϸ��� ����)
	// __PRETTY_FUNCTION__ : g++, clang++ �� ����

	//std::cout << __func__ << std::endl;
	std::cout << __FUNCSIG__ << std::endl;
	
}

int main()
{

	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);	// T = int
	foo(c); // T = int
	foo(r); // T = int
	foo(cr);// T = int 
}
