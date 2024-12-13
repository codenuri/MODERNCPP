// get3.cpp
#include <iostream>
#include "tuple.h"

template<typename T>
void foo(T& tp)
{
	// T : tuple<int, double, short>

	typename tuple_element<0, T>::type n1;	// <= ÇÙ½É

	std::cout << typeid(n1).name() << std::endl;
}

int main()
{
	tuple<int, double, short> t(1, 3.4, 5);

	foo(t);
}


