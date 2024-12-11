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
	auto p2 = std::find_if(v.begin(), v.end(), foo);


	// std::find    : 값 검색,   3번째 인자로 "값" 전달
	// std::find_if : 조건 검색, 3번째 인자로 "함수 전달" 전달
	//										인자가 한개인 단항 함수
}



