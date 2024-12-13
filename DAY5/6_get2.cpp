// get2.cpp
#include <iostream>
#include "tuple.h"

int main()
{
	//	tuple<> t0;					  // primary 사용, 보관하는 데이타 없음. 
	//	tuple<			   short> t1; // short
	//	tuple<	   double, short> t2; // double 보관
	//	tuple<int, double, short> t3; // int 보관

	tuple<int, double, short> t(1, 3.4, 5);

	
	std::cout << t.value << std::endl; // 얼마 나올지 예측해 보세요

	std::cout << t.value << std::endl; // 3.4 나오게 해보세요

	std::cout << t.value << std::endl; // 5 나오게 해보세요
}

