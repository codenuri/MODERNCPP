#include <iostream>
#include <algorithm>
#include <vector>

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3 };

	int k = 3;

	// 주어진 구간에서 k 의 배수를 찾고 싶다.
	// => 위 foo 에서 "n % 3" => "n % k" 로 변경해야 하는데..
	// => foo 에서는 main 의 지역변수 접근 안됩니다.
	// => 그래서 일반 함수로는 힘듭니다.
	// auto p = std::find_if(v.begin(), v.end(), foo );

	// lambda expression 으로는 쉽게 할수 있습니다. 
	// => 지역변수 k를 캡쳐해서 사용하면 됩니다
	// => 람다 표현식의 장점중 한개
	// => 원리는 뒷부분에서 설명.. 
	auto p = std::find_if(v.begin(), v.end(), [k](int n) { return n % k == 0; });
}

