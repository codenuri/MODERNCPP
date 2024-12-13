#include <iostream>

int  hoo(int a) { return -a; }

void goo(int a, int b, int c) {}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3

//	goo(args);	// error. pack 이름 자체를 함수 인자로 사용할수 없습니다
				// pack 을 풀러서(expansion) 해서 보내야 합니다.

	// #1. pack expansion
	// => pack 안의 모든 요소를 , 를 사용해서 열거 하는 기술

	goo(args...);	// goo( 1, 2, 3 ) 의 의미
}


int main()
{
	foo(1, 2, 3);
}
