#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }

// 아래 클래스(함수객체) 잘 생각해 보세요

class IsDivide
{
	int value;
public:
	IsDivide(int v) : value(v) {}

	bool operator()(int n) 	{  return n % value == 0; }
};

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3; 

	IsDivide f(k);		// f 는 k 값을 보관하고 있습니다.
						// f 는 단항함수(인자가 한개인 함수)로 사용가능 합니다.

	bool ret = f(10);	// 10 % k == 0

	auto p1 = std::find_if(v.begin(), v.end(), f);



	std::cout << *p1 << std::endl; // 6


}



