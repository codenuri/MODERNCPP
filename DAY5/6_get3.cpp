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


template<typename T>
void foo(T& tp)
{
	// T : tuple<int, double, short>

	typename tuple_element<0, T>::type n1;	// <= 핵심  int n1
//	typename tuple_element<1, T>::type n2;  // double n2

	std::cout << typeid(n1).name() << std::endl; // int
//	std::cout << typeid(n2).name() << std::endl; // double
}


int main()
{
	tuple<int, double, short> t(1, 3.4, 5);

	foo(t);
}


