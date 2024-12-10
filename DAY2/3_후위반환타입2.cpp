// 후위반환 - 73 page 아래 부분
#include <iostream>

// 아래 ? 채워 보세요
// => 이런 문제를 해결하기 위해서 만든 것이 decltype 입니다.

template<typename T1, typename T2>
//decltype(a * b)  Mul(T1 a, T2 b)	// error. a, b 를 선언전에 사용한것
auto  Mul(T1 a, T2 b) -> decltype(a* b) // ok. 이런 문제를 해결하기 위해 "후위 반환타입" 문법 추가됨.
{
	return a * b;
}

int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;


//	a = 10; // error. a를 선언전에 사용
//	int a = 0;
//	a = 10; // ok. a 를 선언후에 사용
}

