#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }


// �Ϻ��� ������ �Ϸ���
// 1. ���纻�� ����� �ȵǰ�
// 2. ������� �߰��Ǹ� �ȵȴ�.
// => �ᱹ, int&, int&& �� ������ ���� �����ؾ� �Ѵ�.

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
	int n = 10;

	chronometry(foo, 10); // ok.. �ƹ� ���� ����.
	chronometry(goo, n);  // ok. 
						  // �׷���, �� �ڵ�� �Ѱ��� ������ �ֽ��ϴ�.
						  // => ���� �ܰ迡�� ����.. 

	std::cout << n << std::endl;
}
