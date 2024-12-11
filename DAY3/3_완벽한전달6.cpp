#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}


template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	// 아래 2 개의 캐스팅을 잘 구별하세요
//	static_cast<int&&>(arg); // 항상 rvalue 로 캐스팅 하는 코드

//	static_cast<T&&>(arg);	 // 정확한 타입명이 아닌 템플릿 인자 "T"
							 // T 가 int&, int&& 에 따라 달라질수 있다.
							 // => 상황에 따라 달라지는 캐스팅
							 // => 아래 주석 참고
							
	// 아래 캐스팅은 chronometry 인자로
	// 
	// lvalue(n) 을 (전달하면 T=int& 이므로 ) lvalue 로 캐스팅하는 코드(필요없는 캐스팅이지만)
	// rvalue(10)을 (전달하면 받으면서(int&& arg = 10) lvalue로 변경된것을 다시) rvalue 캐스팅

//	f(static_cast<T&&>(arg)); // 이렇게 해도 되는데, C++ 표준에서는

	f(std::forward<T>(arg)); // 이렇게 하기를 권장합니다.	
							// std::forward() 함수가 하는 일이 결국 위와 같은 캐스팅입니다.
							// T&& 가 아닌 T 만 전달.

}

int main()
{
	int n = 0;


	chronometry(foo, 10);	

	chronometry(goo, n);	
}
