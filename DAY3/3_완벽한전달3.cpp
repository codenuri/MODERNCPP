#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }


void hoo(int&& arg) {}



template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10); // ok

	chronometry(hoo, 10); // �Ǿ� �մϴ�. �׷���.. error �Դϴ�.
						  // �� �����ϱ�� ?
						  // => ���ΰ� �ذ�å�� ���� �ҽ�����.. 
}
