// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 전통적인 for 문
	for (int i = 0; i < v.size(); i++)
	{
	}

	// C++11 의 새로운 for 문 - "ranged for" 라고 합니다.
	// 파이썬 : for e in v
	// C#     : foreach(int e in v)
	for (int e : v)
	{
		std::cout << e << ", ";
	}

	// 위 for 문의 원리
	// => 위 코드를 컴파일러가 아래 처럼 변경합니다.

	auto first = std::begin(v); // 또는 v.begin()
	auto last = std::end(v);

	for (; first != last; ++first)
	{
		int e = *first;
		//-----------------------
		std::cout << e << ", ";
	}

}















