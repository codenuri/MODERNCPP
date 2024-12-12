// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits 의 종류
// 1. 타입질의 : is_xxx<T>::value
// 2. 변형타입얻기 : xxx<T>::type

// primary template
template<typename T> struct remove_pointer
{
	using type = T;
};

template<typename T> struct remove_pointer< T* >
{
	using type = T;
};


int main()
{
	remove_pointer<int*>::type n1; // int n1 입니다.
}

template<typename T> void foo(T a)
{
	// 주의 
	// is_pointer<T>::value  => 값 입니다.
	// remove_pointer<T>::type => 타입입니다.

	// remove_pointer 를 T에 의존해서 사용할때는 typename 필요 합니다.

	remove_pointer<int*>::type n1; // typename 필요 없음. T 의존 안함

	typename remove_pointer<T>::type n2; // typename 필요
}
