#include <iostream>

// �߷е� Ÿ���� Ȯ���ϴ� ���
// #1. godbolt.org ��� => ���� ����!!
// #2. ������ �Լ��� �̸��� ��� => ���� ���� ���
// #3. RTTI ��� ��� => ���� ����. ������� ����  

template<typename T> void foo(T a)
{
	a = 100;
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
