#include <algorithm>

int main()
{
	// C++20 �� ���� STL �� �ִ� ��κ��� ǥ���Լ�(algorithm)
	// �� �ٽ� ���� �����մϴ�.
	// => ����� ���� ��ȭ
	// => ���� ���ΰ� �Լ���ü!!

	int n1 = std::max(1, 2);			// C++98. �Ϲ� �Լ�(���ø�) ���� ����
	int n2 = std::ranges::max(1, 2);	// C++20. �Լ� ��ü(���ø�) �Դϴ�
	int n3 = std::ranges::max.operator()(1, 2); // ok. 

}

// C++���� : C++20 ���� ����