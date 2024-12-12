#include <iostream>
#include <vector>
#include <algorithm>

// 아래 Sort 는 비교정책을 함수 포인터로 받아서 사용합니다.
// (C 언어에 있는 qsort 가 이 방식 입니다.)

// 비교정책을 변경 가능하므로 유연성이 있지만
// 직접 비교하는 것에 비해서 성능이 많이 떨어집니다.


// 비교 정책을 교체할수 있는데, 성능 저하가 없이 할수 없을까요 ?
// => 함수 객체로 하면 됩니다. 
// => 다음 소스

void Sort(int* x, int sz, bool(*cmp)(int, int) )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
//			if (x[i] > x[j])			// #1. 직접 비교

			if ( cmp(x[i], x[j]) == false )	// #2. 비교 함수 호출
				std::swap(x[i], x[j]);
		}
	}
}
//-----------------
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };

	Sort(x, 10, cmp1);	// 이제 사용자가 비교 정책을 교체해서
	Sort(x, 10, cmp2);	// sort 의 정책을 변경할수 있습니다.
}

