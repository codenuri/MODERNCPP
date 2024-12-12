// 145 page
#include <iostream>

int main()
{
	// 람다표현식의 정확한 모양
	// => 반환 타입의 표기는 "후위 반환 타입" 표기법 사용
	// => 대부분 생략해도 return 문장으로 추론됨.

	auto f1 = [](int a, int b) -> int { return a + b; };


	// return 문장이 2개 이상이고, 각각 다른 타입을 반환한다면 반드시 표기!

	auto f2 = [](int a, int b)    { if (a == 1) return a; return b; }; // ok
	auto f3 = [](int a, double b) { if (a == 1) return a; return b; }; //error

	auto f4 = [](int a, double b) -> double { if (a == 1) return a; return b; }; // ok
}

