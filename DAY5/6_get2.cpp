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
	
	// 핵심 
	// => 결국 tuple 이 보관한 각 요소에 접근하는 것은 캐스팅(컴파일 시간)일뿐입니다.
	// => 따라서, 실행시 오버헤드는 없습니다.
	
	// 이제 get의 모양을 생각해 봅시다.

	int n = get<0>(t);

	get<0>(t) = 10;
}

template<>
?
get(? )
{

}


