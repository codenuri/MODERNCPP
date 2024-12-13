// get3.cpp
#include <iostream>
#include "tuple.h"

// 결국 tuple_element 는 N == 0, N != 0 의 경우에 해당하는
// 부분 특수화 버전만 사용합니다.
// primary version 은 사용하지 않게 됩니다.
// "이경우는 구조체도 선언만 하면 됩니다.
// 단, 선언은 반드시 있어야 부분 특수화 가능합니다.
template<int N, typename T> struct tuple_element;




// #1. N == 0
template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	// tuple<int, double, short> 의 0번째 요소 타입은 int
	// tuple<int, double, short> 의 0번째 요소 를 저장하는 타입은 자신 즉,tuple<int, double, short> 타입

	using type = T;	// 0번째 요소 타입
	using tuple_type = tuple<T, Types...>;	// 0번째 요소를 저장하는 타입은
};


// #2. N != 0
template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type = typename tuple_element<N - 1, tuple< Types...>>::type;

	using tuple_type = typename tuple_element<N - 1, tuple< Types...>>::tuple_type;
};



template<int N, typename TP >
typename tuple_element<N, TP>::type& 
get(TP& tp)
{
	return static_cast<typename tuple_element<N, TP>::tuple_type&>(tp).value;
}

int main()
{
	tuple<int, double, short> t(1, 3.4, 5);

	get<0>(t) = 10;
	get<1>(t) = 4.3;

	std::cout << get<0>(t) << std::endl;	// 10
	std::cout << get<1>(t) << std::endl;	// 4.3
	std::cout << get<2>(t) << std::endl;	// 5
}


