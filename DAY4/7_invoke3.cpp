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

	return std::invoke(f, std::forward<T>(args)...);
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

// C++ �� ����� �Ϸ���

// 1. C++ �⺻ ���� ��ü�� ���� ��Ȯ�� �˾ƾ� �մϴ�.
// => �ű��, C++11, 14, 17, �׸��� 20 ��
// => C++20 ���� a < b ��� a <=> b �� ����մϴ�. ��
// => godbolt.org �� �� ������ ������ ��Ȯ�� �˾ƾ� �մϴ�.

//-----------------------------
// 2. ������ ������ �ϼ��� - ��ü����. OOP �̷�..

// 3. �� ������ ���� �ְ� �ؾ� �մϴ�. - C++ �߱�
// => ������ �ϳ��� ����� �ص�.. ��ƽ��ϴ�. 
// => new(&pt) Point(1,2) <= �̷� �ڵ带 ���� �ؾ� �մϴ�.
// => trivial
// => callable ���� ����

// 4. template ������ �ѹ� ������ �ʿ� �ֽ��ϴ�.
// => SFINAE, integral constant

// 5. STL ���̺귯�� ����
// => move iterator, counted iterator, reverse iterator��.. 
// => ���� ���� ���̺귯���� �ֽ��ϴ�.

// 6. Concurrent ���̺귯��.. 

// �ʵ�
// => effective C++ �ø���, effective modern C++..





