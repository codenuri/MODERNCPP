#include <iostream>
#include <vector>
#include <algorithm>

// 람다표현식과 타입

int main()
{
	auto f1 = [](int a, int b) { return a + b; };
				// class xxx{ operator() }; xxx{};

	auto f2 = [](int a, int b) { return a + b; };
				//  class yyy{ operator() }; yyy{};

	// 핵심 : 모든 람다표현식은 "다른 타입" 입니다.
	// 1. godbolt.org 에서도 확인 가능 하고
	// 2. 아래 처럼 타입이름 구해서 출력해 보면 됩니다.

	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;



}





