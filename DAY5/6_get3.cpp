// get3.cpp
#include <iostream>
#include "tuple.h"

// #1. 사용하는 코드를 잘 생각해서, primary template 을 작성 합니다.
template<int N, typename T> struct tuple_element
{
	// 튜플 T에서 N 번째 요소의 타입을 ? 에 표기해야 합니다.
	// 그런데, 현재 코드에서는 알수 없습니다.
	// using type = ? ;

	// 그래서, 구할수 있도록 부분 특수화 기술을 사용해야 합니다.
};

//=============================================
// #1. N == 0 일때를 위한 부분 특수화
/*
template<typename T> struct tuple_element<0, T>
{
	using type = 튜플T의 0번째 요소의 타입을 표기해야 하는데;

	// 아직 구할수 없습니다.
	// 잘못된 부분 특수화
};
*/
/*
template<typename ... Types> struct tuple_element<0, tuple<Types...> >
{
//	using type = tuple<Types...> 의 0번째 요소의 타입을 표기해야 하는데;

	// 역시 0번째 타입을 구할수 없다.
	// 잘못된 부분 특수화
};
*/
// 핵심 : 튜플의 0번째 타입을 알아낼수 있도록 부분 특수화를 잘해야 합니다.
template<typename T, typename ... Types> 
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;
};

//=====================================
// #2. N != 0 
template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	// tuple<int, double, short> 의 2번째 요소의 타입(short) 는
	// tuple<     double, short> 의 1번째 요소의 타입이고
	// tuple<             short> 의 0번째 요소의 타입입니다.
	// => 즉, 1번째 타입을 버리고, N-1 을 구하면 됩니다.
	// => recursive 하게 조사하면서 N==0을 만들면 된다.

	using type = typename tuple_element<N - 1, tuple< Types...>>::type;
};


template<typename T>
void foo(T& tp)
{
	// T : tuple<int, double, short>

	typename tuple_element<0, T>::type n1;	// <= 핵심  int n1
	typename tuple_element<1, T>::type n2;  // double n2

	std::cout << typeid(n1).name() << std::endl; // int
	std::cout << typeid(n2).name() << std::endl; // double
}


int main()
{
	tuple<int, double, short> t(1, 3.4, 5);

	foo(t);
}


