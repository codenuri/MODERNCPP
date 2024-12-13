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

//=============================================
// #1. N == 0 �϶��� ���� �κ� Ư��ȭ
/*
template<typename T> struct tuple_element<0, T>
{
	using type = Ʃ��T�� 0��° ����� Ÿ���� ǥ���ؾ� �ϴµ�;

	// ���� ���Ҽ� �����ϴ�.
	// �߸��� �κ� Ư��ȭ
};
*/
/*
template<typename ... Types> struct tuple_element<0, tuple<Types...> >
{
//	using type = tuple<Types...> �� 0��° ����� Ÿ���� ǥ���ؾ� �ϴµ�;

	// ���� 0��° Ÿ���� ���Ҽ� ����.
	// �߸��� �κ� Ư��ȭ
};
*/
// �ٽ� : Ʃ���� 0��° Ÿ���� �˾Ƴ��� �ֵ��� �κ� Ư��ȭ�� ���ؾ� �մϴ�.
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
	// tuple<int, double, short> �� 2��° ����� Ÿ��(short) ��
	// tuple<     double, short> �� 1��° ����� Ÿ���̰�
	// tuple<             short> �� 0��° ����� Ÿ���Դϴ�.
	// => ��, 1��° Ÿ���� ������, N-1 �� ���ϸ� �˴ϴ�.
	// => recursive �ϰ� �����ϸ鼭 N==0�� ����� �ȴ�.

	using type = typename tuple_element<N - 1, tuple< Types...>>::type;
};


template<typename T>
void foo(T& tp)
{
	// T : tuple<int, double, short>

	typename tuple_element<0, T>::type n1;	// <= �ٽ�  int n1
	typename tuple_element<1, T>::type n2;  // double n2

	std::cout << typeid(n1).name() << std::endl; // int
	std::cout << typeid(n2).name() << std::endl; // double
}


int main()
{
	tuple<int, double, short> t(1, 3.4, 5);

	foo(t);
}


