#include <iostream>
#include <type_traits>

// C++ 표준에 있는 remove_pointer 는 포인터를 한개만 제거한 타입을 구하게됩니다.
// 포인터를 모두 제거한 타입을 구하는 traits 를 만들어 봅시다.

template<typename T> struct remove_all_pointer
{
	using type = T;
};

template<typename T> struct remove_all_pointer< T* >
{
	using type = typename remove_all_pointer<T>::type;
};

int main()
{
	remove_all_pointer< int*** >::type n;

	std::cout << typeid(n).name() << std::endl; // int

	// 참고 : C++ 표준에는 remove_all_pointer 는 없습니다.
}
