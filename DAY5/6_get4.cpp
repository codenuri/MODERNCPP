// get3.cpp
#include <iostream>
#include "tuple.h"

// #1. ����ϴ� �ڵ带 �� �����ؼ�, primary template �� �ۼ� �մϴ�.
template<int N, typename T> struct tuple_element
{
	// Ʃ�� T���� N ��° ����� Ÿ���� ? �� ǥ���ؾ� �մϴ�.
	// �׷���, ���� �ڵ忡���� �˼� �����ϴ�.
	// using type = ? ;

	// �׷���, ���Ҽ� �ֵ��� �κ� Ư��ȭ ����� ����ؾ� �մϴ�.
};

// #1. N == 0
template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	// tuple<int, double, short> �� 0��° ��� Ÿ���� int
	// tuple<int, double, short> �� 0��° ��� �� �����ϴ� Ÿ���� �ڽ� ��,tuple<int, double, short> Ÿ��

	using type = T;	// 0��° ��� Ÿ��
	using tuple_type = tuple<T, Types...>;	// 0��° ��Ҹ� �����ϴ� Ÿ����
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


