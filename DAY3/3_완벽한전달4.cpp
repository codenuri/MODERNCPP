#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }


void hoo(int&& arg) {}

// main						chronometry						hoo(int&&)
// hoo(10) ==================================================> ok
// chronometry(10) =======> int&& arg = 10	
//							hoo(arg) ========================> error. arg는 lvalue		
//					해결책  	hoo(static_cast<int&&>(arg)) ====> ok
// 	
template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F> void chronometry(F f, int&& arg)
{
//	f(arg);	// hoo(arg) 인데, arg 는 lvalue 이므로 hoo(int&) 를 찾게 된다.
	f( static_cast<int&&>(arg) ); // ok

	// 결국, chronometry(10) 의 "10" 은 rvalue 였는데..
	// int&& arg = 10 으로 받으면서 art 는 lvalue 가 된것
	// 다른 함수에 보낼때는 다시 rvalue 로 캐스팅해서 전달
}

int main()
{
	hoo(10); 

	chronometry(hoo, 10); 
}
