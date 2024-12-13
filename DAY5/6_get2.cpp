// get2.cpp
#include <iostream>
#include "tuple.h"

int main()
{
	//	tuple<> t0;					  // primary 사용, 보관하는 데이타 없음. 
	// 
	//	tuple<			   short> t1;			// short 보관 5
	// 
	//	tuple<	   double, short> t2;			// double 보관 3.4
	// 
	//	tuple<int, double, short> t3(1, 3.4, 5); // int 보관  1


	tuple<int, double, short> t(1, 3.4, 5);

	
	std::cout << t.value << std::endl; // 1

	std::cout << static_cast<tuple<double, short>&>(t).value << std::endl; // 3.4 나오게 해보세요

	std::cout << static_cast<tuple<short>&>(t).value << std::endl; // 5 나오게 해보세요
}

