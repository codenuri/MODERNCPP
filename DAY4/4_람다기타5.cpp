#include <iostream>

class CompilerGeneratedName
{
	int v1;
	int v2;
public:
	CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

	inline  int operator()(int a, int b) const { return a + b + v1 + v2;} // ok


	// ���� ������ ���� �ϴ� static ��� �Լ��� ������ �ϴµ�..
	// ������ static ��� �Լ������� �������Ÿ�� v1, v2 �� �����Ҽ� �����ϴ�.
	// ����, �Ʒ� �Լ��� ������ ���� �����ϴ�.
	// => �׷��� �Լ� �����ͷ��� ��ȯ�� �������� �ʽ��ϴ�.
	static int helper(int a, int b) { return a + b + v1 + v2; } // error


	using F = int(*)(int, int);
	operator F() { return &CompilerGeneratedName::helper; }
};


int main()
{
	// #1. ĸ������ ���� ���� ǥ������ �Լ� �����ͷ� ��ȯ �˴ϴ�.
	int(*f1)(int, int) = [](int a, int b) {return a + b; };	// ok


	// #2. ������ ĸ���� ����ǥ������ �Լ� ������ ��ȯ �ȵ˴ϴ�.
	// => �� �׷���� ? 
	// => �� �ҽ� ���� �ϼ���
	int v1 = 0, v2 = 0;
	int(*f2)(int, int) = [v1, v2](int a, int b) {return a + b + v1 + v2; }; // error
}

// 1. ������ ���� ��ȭ/�߰�
// 2. Ÿ���߷�, �ʱ�ȭ
// 3. move �̾߱��, lvalue/rvalue, rvalue reference
// 4. perfect forwarding, forwarding reference
// 5. lambda expression, function object(�Լ���ü)
// -----------------------------------------------
// 6. traits ���, �������� : �κ�Ư��ȭ, enable_if = template ����










