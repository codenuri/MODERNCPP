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
	// => foo 안에서 3대신 "k" 를 사용해야 하는데, main 지역변수 k를
	//    foo 에서 사용할수 없습니다.
	// => 전역변수등을 사용할수밖에 없습니다.
	auto p1 = std::find_if(v.begin(), v.end(), foo);

	// 일반함수는 어렵지만, 함수 객체로 하면 아주 간단합니다.
	// => 다음소스.. 
}



