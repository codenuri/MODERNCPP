#include <iostream>
#include <type_traits>

void foo(...) { std::cout << "..." << std::endl; }

/*
template<typename T>
void foo(T n)
{
	typename T::type n;	// SFINAE 가 적용될까요 ?
						// 에러 입니다. SFINAE 적용안됩니다.
}
*/
// SFINAE 는 함수의 signature 에서만 적용됩니다.
// => 함수 반환 타입, 인자 타입, template 인자 타입
// #1. 함수 반환 타입
// template<typename T>
//typename T::type foo(T n) { return 0; }


// #2. 함수 인자
// template<typename T>
// void foo(T n, typename T::type a = 0 ) {  }


// #3. 템플릿 인자
template<typename T, typename T2 = typename T::type >
void foo(T n) {}

// 대부분 SFINAE 를 활용하는 경우는
// => 반환 타입에 사용하는 경우가 많습니다
// => enable_if 예제 참고.. 

int main()
{
	foo(0);
}