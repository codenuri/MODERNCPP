#include <iostream>

int x = 10;

class Test
{
	int value1 = 0;   // ok. ���� �ڵ�
	int value2 = ++x; // ������ �ƴ����� ���� �̷��� ���� ������
					  // ȥ�������� �˴ϴ�.!!!!!
					  // �� ��ġ�� = 0 ���� �ʱ�ȭ�� ����ϼ���. 
public:
	// ����� �ڵ�					// �����Ϸ��� ������ �ڵ�
	Test() {}						// Test()      : value1(0), value2(++x) {} <= 1
	Test(int n) : value2(n) {}		// Test(int n) : value1(0), value2(n) {}   <= 2
};

int main()
{
	Test t1;	// 1�� ������ ȣ��, ++x ����
	Test t2(5);	// 2�� ������ ȣ��, ++x ���� �ȵ�. 

	std::cout << x << std::endl; // ���.. �����غ�����. ?
								// 11 
}
