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
	// => "pack이름..."                => e1, e2, e3
	// => "pack이름을 사용하는 연산..." => e1연산, e2연산, e3연산

	goo( args... );		// goo( 1, 2, 3 ) 의 의미
	goo( (++args)...);	// goo( ++e1, ++e2, ++e3),  () 없어도 됩니다.

//	goo(hoo(args...));  // 어떻게 풀리는지 생각해 보세요
						// goo( hoo(e1, e2, e3)) 인데, hoo()는 인자가 한개이므로 error

	goo( hoo(args)... ); // goo(hoo(e1), hoo(e2), hoo(e3)) 의 의미.. ok

	// 핵심
	// 위 예제를 통해서, ... 의 위치에 따른 차이점을 정확히 알아 두세요

}


int main()
{
	foo(1, 2, 3);
}
