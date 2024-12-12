#include <iostream>
#include <vector>
#include <algorithm>


void Sort(int* x, int sz, bool(*cmp)(int, int) )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
//			if (x[i] > x[j])

			if ( cmp(x[i], x[j]) == false )
				std::swap(x[i], x[j]);
		}
	}
}
//-----------------
bool cmp1(int a, int b) { return a < b; }
bool cmp2(int a, int b) { return a > b; }

int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };

	Sort(x, 10, cmp1);	// 이제 사용자가 비교 정책을 교체해서
	Sort(x, 10, cmp2);	// sort 의 정책을 변경할수 있습니다.
}

