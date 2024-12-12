#include <algorithm>

int main()
{
	// C++20 은 기존 STL 에 있던 대부분의 표준함수(algorithm)
	// 을 다시 만들어서 제공합니다.
	// => 기능이 대폭 강화

	int n1 = std::max(1, 2);			// C++98. 일반 함수(템플릿) 으로 구현
	int n2 = std::ranges::max(1, 2);	// C++20. 함수 객체(템플릿) 입니다

}