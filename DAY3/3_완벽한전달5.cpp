#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}


/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);	
	f(static_cast<int&>(arg));	// 필요없는 캐스팅 입니다.
								// 하지만 있어도 문제 없고, 컴파일시 제거 됩니다.
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}
*/
// 완벽한 전달 하려면 "int&, int&&" 버전이 각각 필요합니다.

// forwarding reference(T&&) 를 사용하면 위 2개 함수를 자동생성할수 있습니다.

template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 0;
	
	// 아래 코드의 결과로 생성된 함수 모양과, 캐스팅 코드를 예상해 보세요

	chronometry(foo, 10);	// T = int,   T&& = int&&
							// chronometry(F, int&& arg )
							// static_cast<int&&>(arg)

	chronometry(goo, n);	// T = int&,   T&& = int& && => int&
							// chronometry(F,  int& arg )
							// static_cast<int&>(arg)
}
