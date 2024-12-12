#include <iostream>

// #1. �Լ��� �ڽŸ��� Ÿ���� ����.
//     signature(���� Ÿ�԰� ���� ���)�� ������ �Լ��� ��� ���� Ÿ���̴�.

// #2. �Լ���ü�� �ڽŸ��� Ÿ���� �ִ�.
//     signature(���� Ÿ�԰� ���� ���)�� �����ص� ��� �Լ� ��ü�� �ٸ� Ÿ���̴�.

struct Less    { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

//-------------------------------
// �Ʒ� �ڵ�� "�� ��å �� ��ü" �Ҽ� �ְ�
// �� ��å �Լ��� "�ζ��� ġȯ"�� �����մϴ�.
// => �Լ� ��ü�� template ���� ����� ���
// => STL �� �ٽ� ���� ���� �Դϴ�.

template<typename T>
void Sort(int* x, int sz, T cmp )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (cmp(x[i], x[j]) == false)	
				std::swap(x[i], x[j]);
		}
	}
}

int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(5, 3); Sort(x, 10, f1); // ok
	Greater f2; f2(5, 3); Sort(x, 10, f2); // ??
}