#include <iostream>
#include <functional>

class Test
{
public:
	void mf(int n, double d) {}
};

void foo(int n, double d) {}


template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... args)
{
	// stop_watch sw(true);

//	return f(std::forward<T>(arg)...);  // �̷��� �ϸ� f �� �Ϲ� �Լ� �����ʹ� ���� ������
										// ��� �Լ� ������ ��� error �Դϴ�.

	return std::invoke(f, std::forward<T>(arg)...);
				// �̷��� �ؾ�, main �Լ� ó��
				// �Ϲ��Լ�, ��� �Լ��� ��� �����մϴ�.
}

int main()
{
	chronometry(&foo, 1, 3.4);	// foo(1, 3.4) �� �ҿ� �ð� ����

	// ��� �Լ��� "�Լ� �ּҿ� ��ü�ּ�, ���ڵ�"�� ����
	Test test;
	chronometry(&Test::mf, &test, 1, 3.4); // test.mf(1, 3.4) �� �ҿ�ð� ����
}