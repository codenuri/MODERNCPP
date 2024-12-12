#include <iostream>
#include <type_traits>


// 변수 선언문에서 "변수 이름만 제외" 하면 "타입" 이 됩니다

int n;		// n 의 타입은 int

double d;	// d 의 타입은 double

int x[3];	// x 의 타입은 int[3]
			//			    T[N] => 임의 타입의 임의 크기를 가지는 배열 타입
			//				T[]	 => unknown size array 라는 타입





template<typename T> struct is_array
{
	static constexpr bool value = false;	
};

template<typename T, int N> struct is_array< T[N] >
{
	static constexpr bool value = true;
};


template<typename T> void foo(T& a)
{
	// is_array 만들어 보세요
	if ( is_array<T>::value ) 
		std::cout << "배열" << std::endl;
	else
		std::cout << "배열 아님" << std::endl;
}
int main()
{
	int arr[3] = { 1,2,3 };
	foo(arr);
}
