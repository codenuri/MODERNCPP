#include <iostream>
#include <algorithm>
#include <functional> // C++표준에서 제공하는 다양한 함수 객체들 - C++98
// std::less<>, std::greater<>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };


	// 아래 코드에 대해서 평가 해보세요 ( 문제점 찾아 보세요 )
	// => 동일한 람다 표현식을 3번 사용했지만 모두 다른 타입 입니다.
	// => sort 함수가 3개 생성 됩니다
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// 동일한 람다 표현식이 여러번 사용된다면 auto 에 담아서 사용하세요
	// => 아래 코드는 "한개의 sort" 만 생성 됩니다.
	auto cmp = [](int a, int b) { return a < b; };

	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);


	// 그런데, 람다표현식은 결국 함수 객체를 만드는 것이고
	// < 를 위한 함수 객체는 이미 std::less 가 있습니다.
	// 람다 대신 std::less 를 사용하는 것도 권장. 

	std::less<int> f;
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), f);

	// 아래 처럼 임시객체로 해도 문제 없습니다.
	// => 생성자 호출등은 모두 사라집니다.( = default 로 만들어진것들, 최적화!)
	std::sort(v.begin(), v.end(), std::less<int>{});
	std::sort(v.begin(), v.end(), std::less<int>{});
	std::sort(v.begin(), v.end(), std::less<int>{});
}






