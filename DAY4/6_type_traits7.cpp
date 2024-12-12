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




