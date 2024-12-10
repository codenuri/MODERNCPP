#include <iostream>""

// ��ȯ Ÿ���� ����ڰ� ��Ȯ�� ǥ�� �Ѱ�
// => C++11 ���� ����
// => return ������ ������ �־ ����, �ᱹ ���� Ÿ���� "decltype(a* b)" �̹Ƿ�
// => decltype ��Ģ�� ����ϹǷ� decltype(a*b) �� ������ �����Ǹ� 
//    ��ȯ Ÿ�Ե� ����(�Ʒ� �ڵ�� �� Ÿ��)
template<typename T1, typename T2>
auto  Mul1(T1 a, T2 b) -> decltype(a* b) 
{
	if (a == 0) return 0;
	return a * b;
}

// �����Ϸ����� ���� ������ ���� ��ȯ Ÿ���� �߷��� �޶�� �Ѱ�
// => C++14 ���� ����
// => return ������ 2�� �̻��̸� error. 
// => �Ʒ� �ڵ�� auto ��Ģ ���
//    "auto a = return����" ���� �ε�,
//     auto ��Ģ �̹Ƿ� "return����" �� ����� reference ��, ��ȯ Ÿ���� �� Ÿ��. 
template<typename T1, typename T2>
auto  Mul2(T1 a, T2 b)
{
	if (a == 0) return 0;

	return a * b;
}

// �ᱹ, return ������ �Ѱ��� Mul, Add, Sub���� ���鶧��
// => auto �� ǥ���ص� �˴ϴ�. (C++14 �̻�)
// => �Լ������� �����ؼ� 2���̻��� return ���� �ְų�
//    "return ǥ����"�� �����϶� ��ȯŸ�Ե� ������ �ϰ� �ʹٸ� decltype() ���


int main()
{
	std::cout << Mul1(3, 4.1) << std::endl;
	std::cout << Mul2(3, 4.1) << std::endl;

}

