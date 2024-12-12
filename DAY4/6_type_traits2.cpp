#include <iostream>
#include <type_traits>

// 템플리 인자 T 가 포인터 인지 알아내는 기술

template<typename T> struct is_pointer
{
	// enum 을 사용한 이유
//	bool value = false;		// 1. C++98 시절에는 이렇게 초기화 할수 없었고
							// 2. 이렇게 하면 컴파일 시간 상수가 아니다.
//	enum { value = false };	// 그래서 C++98 시절에 사용할수 있는 유일한 코드
							// "enum hack" 이라는 이름을 가진 기술

	// C++11 이후 부터는 constexpr 사용
	static constexpr bool value = false;	// 위 enum 은 value 가 int 지만
											// 이 코드에서 value 는 bool 
};

template<typename T> struct is_pointer< T* >
{
//	enum { value = true };
	static constexpr bool value = true;
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
