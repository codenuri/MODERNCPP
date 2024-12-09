#include <iostream>
#include <vector>
#include <ranges>

// 아래 클래스에 대해서 잘생각해 보세요
// => C++20 부터 아래와 같은 다양한 시각(view)가 추가됩니다.
// => 30 여개가 있습니다.
template<typename T> 
class take_view
{
	T& rng;
	int cnt;
public:
	take_view(T& r, int c) : rng(r), cnt(c) {}

	auto begin() { return rng.begin(); }
	auto end() { return rng.begin() + cnt; }
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
//	take_view< std::vector<int> > tv(v, 3); // v의 요소를 3개만 볼수 있는 view
//	take_view tv(v, 3); // C++17 부터 템플릿 인자 생략가능. 
						// => 프로젝트 메뉴
						// => DAY1 속성메뉴에서 C++ 버전을 C++17 로 맞추어야 합니다.

//	for (int e : tv)
//	for (int e : take_view(v, 3) ) // 임시객체 형태로 사용. 
	for (int e : std::ranges::reverse_view(v)) // C++20 부터 제공. 
	{
		std::cout << e << ", ";
	}
}















