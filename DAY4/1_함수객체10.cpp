// chronometry.h ���� �߰� �ϼ��� - git �� �ִ� �ҽ� ���� �ϼ���
// 1_�Լ���ü10.cpp -
#include <vector>
#include <algorithm>
#include "chronometry.h"

const std::size_t count = 1000000;

std::vector<int> v1;
std::vector<int> v2;

void init()
{
	// v1, v2 �� ���� ����Ÿ�� ä��ϴ�.
	v1.reserve(count);
	v2.reserve(count);

	for (int i = 0; i < count; i++)
	{
		int n = rand();
		v1.push_back(n);
		v2.push_back(n);
	}
}

void ex1()
{
	std::sort(v1.begin(), v1.end(), cmp1);
	std::sort(v1.begin(), v1.end(), cmp2);
}
void ex2()
{
	std::sort(v2.begin(), v2.end(), Less{});
	std::sort(v2.begin(), v2.end(), Greater{});
}

int main()
{
	init();

	chronometry(ex1);
	chronometry(ex2);
}