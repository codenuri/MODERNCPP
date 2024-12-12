// 4_type_traits3 - 210 page
#include <iostream>

// is_pointer, is_array, remove_pointer 등은 이미 C++ 표준에 있습니다.
// => C++11 부터 지원

// #1. 표준  traits 를 사용하려면 아래 헤더 추가 
#include <type_traits>

template<typename T> void foo(T a)
{
	// #2. 조사하려면, std::is_xxx<T>::value 형태
	bool b1 = std::is_pointer<T>::value;	// C++11 스타일 
	bool b2 = std::is_pointer_v<T>;			// C++17 스타일


	// #3. 변형 타입을 얻으려면 "::type" 형태 
	typename std::remove_pointer<T>::type n1;	// C++11 스타일

	remove_pointer_t<T> n2; // 위와 완전히 동일      C++14 스타일
}

// C++14 부터 아래 코드가 표준에 추가됩니다.
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;



int main()
{
	int n = 0;
	foo(&n);
}
