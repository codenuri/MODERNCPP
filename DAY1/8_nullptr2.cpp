// 8_nullptr2
#include <iostream>

/*
void foo(int* p) {}


int main()
{
	int n = 0;

	foo(0); // ok. 0은 int 타입이지만, 포인터로 암시적 형변환 가능.

	foo(n);	// error. 리터럴 0 은 포인터로 암시적 형변환 되지만
			//        0으로 초기화된 int 변수는 포인터로 암시적 변환될수 없다.
}
*/

// 위 코드를 잘 생각하면서 아래 코드를 보세요
void foo(int* p) {}


template<typename F, typename ARG>
void forward_parameter(F f, ARG arg)
{
	f(arg);
}

int main()
{
	foo(0); // ok

	forward_parameter(foo, 0); // foo 함수에 0을 전달해 달라는 것
}




