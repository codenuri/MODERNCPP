#include <iostream>
#include <type_traits>

// 
/*
template<typename T> void printv(const T & v)
{
	if constexpr (std::is_pointer_v<T>)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}
*/
// if constexpr 는 C++17 기술 입니다.
// C++17 이전에는 사용할수 없었습니다.
// std::enable_if 로 하면 됩니다.

template<typename T>
std::enable_if_t< std::is_pointer_v<T> >
printv(const T& v)
{
	std::cout << "포인터인 경우\n";
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> 
std::enable_if_t< !std::is_pointer_v<T> >
printv(const T& v)
{
	std::cout << "포인터가 아닌 경우\n";
	std::cout << v << std::endl;
}


int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}