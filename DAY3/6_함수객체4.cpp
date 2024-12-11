#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3; // 사용자가 입력한 값이라고 가정

	// 주어진 구간에서 "k의 배수" 를 찾고 싶다 ???
	// => 어떻게 해야 할까요 ?
	auto p1 = std::find_if(v.begin(), v.end(), foo);

}



