#include <iostream>
#include <algorithm>
#include <functional> // C++표준에서 제공하는 다양한 함수 객체들 - C++98
// std::less<>, std::greater<>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };


	// 아래 코드에 대해서 평가 해보세요 ( 문제점 찾아 보세요 )
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
}





