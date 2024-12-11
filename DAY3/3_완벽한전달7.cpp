#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}

// �ٽ� ���� : ���� ���ڸ� �ٸ� �Լ��� �Ϻ��ϰ� �����Ϸ���
// 1. ���ڸ� ������ forwarding reference(T&&) �� ��������
// 2. �ٸ� ���� �����Ҷ��� "std::forward<T>(arg)" �� �����ؾ� �մϴ�.

// T&& : �ᱹ perfect forwarding ���� ���ǹǷ�
//		 "forwarding reference" ��� �̸��� ���߽��ϴ�.

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f( std::forward<T>(arg) ); 
}

int main()
{
	int n = 0;


	chronometry(foo, 10);

	chronometry(goo, n);
}
