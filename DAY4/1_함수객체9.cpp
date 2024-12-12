#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less    { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };
	
	// std::sort() �� ��� ���ڰ� ���ø� �Դϴ�.
	// => ����ڰ� ������ ���ڿ� ���� �Լ��� �����ȴٴ� �ǹ�

	// #1. �� ��å���� �Ϲ��Լ��� ����ϴ� ���

	// ���� : �� ��å�� ������ ��ü �ؼ� �����Ǵ� sort() �Լ��� �Ѱ��̴�.
	//	      �ڵ� �޸� ���� ���� �ʴ´�.

	// ���� : �� ��å �Լ��� �ζ��� ġȯ �ɼ� �����ϴ�
	//        �����ϴ�.

	std::sort(x, x + 10, cmp1); // sort(int*, int*, bool(*)(int, int)) �� �Լ� ����
	std::sort(x, x + 10, cmp2); // sort(int*, int*, bool(*)(int, int)) �� �Լ� ����





	// #2. �� ��å���� �Լ���ü�� ����ϴ� ���
	
	// ���� : �� ��å�� ��ü�� Ƚ�� ��ŭ�� sort() �Լ� ����.
	//		  �ڵ� �޸� ����
	// 
	// ���� : �� ��å�� �ζ��� ġȯ ����. ������.

	Less f1;
	Greater f2;
	std::sort(x, x + 10, f1);	// sort(int*, int*, Less) �� �Լ� ����
	std::sort(x, x + 10, f2);	// sort(int*, int*, Greater) �� �Լ� ����

}