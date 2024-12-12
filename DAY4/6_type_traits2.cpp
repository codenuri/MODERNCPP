#include <iostream>
#include <type_traits>

// 템플리 인자 T 가 포인터 인지 알아내는 기술

template<typename T> struct is_pointer
{
	enum { value = false };
};

template<typename T> void foo(const T& a)
{
	// 현재 T는 : int, int* 입니다 (main 참고)
	if ( is_pointer<T>::value )
		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}

int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}
