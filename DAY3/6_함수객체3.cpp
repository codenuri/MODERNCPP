#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };


	// 주어진 구간에서 "3"을 찾고 싶다. 
	auto p1 = std::find(v.begin(), v.end(), 3);




	// 주어진 구간에서 "3의 배수"를 찾고 싶다. 
	auto p1 = std::find_if(v.begin(), v.end(), foo);


	int k = 0;
	std::cin >> k;
}



