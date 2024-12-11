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

	bool operator()(int n)
	{
		return n % value == 0;
	}
};

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3; 

	IsDivide f(k);
	bool ret = f(10);

	auto p1 = std::find_if(v.begin(), v.end(), foo);


}



