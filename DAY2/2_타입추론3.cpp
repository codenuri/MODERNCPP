#include <iostream>

// 규칙 #2. 인자의 타입이 lvalue reference(T&) 일때
// => 함수 인자가 가진 reference 속성만 제거하고 T 타입 결정
// => 함수 인자의 const, volatile 속성은 유지
// => T의 타입이 결정되면 a의 타입은 T&
template<typename T> void foo(T& a)
{
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);		// T = int			a = int&
	foo(c);		// T = const int	a = const int&
	foo(r);		// T = int			a = int&
	foo(cr);	// T = const int	a = const int&
}
