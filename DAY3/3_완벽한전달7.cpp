#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}

// 핵심 정리 : 받은 인자를 다른 함수에 완벽하게 전달하려면
// 1. 인자를 받을때 forwarding reference(T&&) 로 받으세요
// 2. 다른 곳에 전달할때는 "std::forward<T>(arg)" 로 전달해야 합니다.

// T&& : 결국 perfect forwarding 에서 사용되므로
//		 "forwarding reference" 라고 이름을 정했습니다.

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f( std::forward<T>(arg) ); 
}

int main()
{
	int n = 0;


	chronometry(foo, 10);

	chronometry(goo, n);
}
