#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}


template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	// �Ʒ� 2 ���� ĳ������ �� �����ϼ���
//	static_cast<int&&>(arg); // �׻� rvalue �� ĳ���� �ϴ� �ڵ�

//	static_cast<T&&>(arg);	 // ��Ȯ�� Ÿ�Ը��� �ƴ� ���ø� ���� "T"
							 // T �� int&, int&& �� ���� �޶����� �ִ�.
							 // => ��Ȳ�� ���� �޶����� ĳ����
							 // => �Ʒ� �ּ� ����
							
	// �Ʒ� ĳ������ chronometry ���ڷ�
	// 
	// lvalue(n) �� (�����ϸ� T=int& �̹Ƿ� ) lvalue �� ĳ�����ϴ� �ڵ�(�ʿ���� ĳ����������)
	// rvalue(10)�� (�����ϸ� �����鼭(int&& arg = 10) lvalue�� ����Ȱ��� �ٽ�) rvalue ĳ����

//	f(static_cast<T&&>(arg)); // �̷��� �ص� �Ǵµ�, C++ ǥ�ؿ�����

	f(std::forward<T>(arg)); // �̷��� �ϱ⸦ �����մϴ�.	
							// std::forward() �Լ��� �ϴ� ���� �ᱹ ���� ���� ĳ�����Դϴ�.
							// T&& �� �ƴ� T �� ����.

}

int main()
{
	int n = 0;


	chronometry(foo, 10);	

	chronometry(goo, n);	
}
