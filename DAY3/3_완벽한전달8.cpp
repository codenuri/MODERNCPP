#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}

void f0() {}
int& f3(int a, double d, int& r) { r = 100; return r; }

// �Ϻ��� ������ �ڵ� ����
// 1. ���� ������ ������ ���ֱ� ���ؼ� "�������� ���ø�(5�������³���)" ���
// 2. ��ȯ ���� �Ϻ��� �����־�� �մϴ�. - decltype(auto) �� ��ȯ

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	// StopWatch sw;  // �����ڿ��� �ð� ���
					  // �Ҹ��ڿ��� ����ð� ȭ�� ���
	return f(std::forward<T>(arg)... );
}

int main()
{
	int n = 0;
	
	chronometry(f0); // f0()
	
	int& ret = chronometry(f3, 1, 3.4, n); // f3(1, 3.4, n)

	ret = 300; // n = 300
	std::cout << n << std::endl; // 300
}
