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


template<typename T>
void foo(T& tp)
{
	// T : tuple<int, double, short>

	typename tuple_element<0, T>::type n1;	// <= �ٽ�  int n1
//	typename tuple_element<1, T>::type n2;  // double n2

	std::cout << typeid(n1).name() << std::endl; // int
//	std::cout << typeid(n2).name() << std::endl; // double
}


int main()
{
	tuple<int, double, short> t(1, 3.4, 5);

	foo(t);
}


