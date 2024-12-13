#include <iostream>
#include <type_traits>


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