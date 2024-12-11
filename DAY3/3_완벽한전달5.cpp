#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}


/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);	
	f(static_cast<int&>(arg));	// �ʿ���� ĳ���� �Դϴ�.
								// ������ �־ ���� ����, �����Ͻ� ���� �˴ϴ�.
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}
*/
// �Ϻ��� ���� �Ϸ��� "int&, int&&" ������ ���� �ʿ��մϴ�.

// forwarding reference(T&&) �� ����ϸ� �� 2�� �Լ��� �ڵ������Ҽ� �ֽ��ϴ�.

template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 0;
	
	// �Ʒ� �ڵ��� ����� ������ �Լ� ����, ĳ���� �ڵ带 ������ ������

	chronometry(foo, 10);	// T = int,   T&& = int&&
							// chronometry(F, int&& arg )
							// static_cast<int&&>(arg)

	chronometry(goo, n);	// T = int&,   T&& = int& && => int&
							// chronometry(F,  int& arg )
							// static_cast<int&>(arg)
}
