#include <iostream>
#include <type_traits>

// 아래 한글부분 코드로 변경해 보세요 - std::is_pointer 사용
// => std::is_pointer_v 가 편리합니다.




template<typename T> void printv(const T& v)
{
//	if ( std::is_pointer_v<T> )
	if constexpr (std::is_pointer_v<T>)

		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}

// 정리
// template instantiation : 템플릿 으로 부터 진짜 함수(클래스)를 만드는 과정

template<typename T> void printv(const T& v)
{
	if (std::is_pointer_v<T>)
	{
		// 컴파일 시간에 조건식이 false 로 결정되어도 
		// 이부분은 template instantiation 에 포함됩니다.
		// *v 같은 코드가 있으면 컴파일 에러
	}

	if constexpr (std::is_pointer_v<T>)
	{
		// 컴파일 시간에 조건식이 false 로 결정되어도 
		// 이부분은 template instantiation 에 포함안됩니다.
		// *v 같은 코드가 있어도, 실제 함수에는 포함되지 않으므로 에러 아닙니다.
	}
}

// 위와 같은 문제를 해결하는 주된 방법은 4가지가 있습니다
// 1. std::integral_constant - C++11
// 2. std::enable_if         - C++11
// 3. if constexpr			 - C++17    ==> 위 코드 참고
// 4. concept				 - C++20 

