#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }


void hoo(int&& arg) {}



template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10); // ok

	chronometry(hoo, 10); // 되야 합니다. 그런데.. error 입니다.
						  // 왜 에러일까요 ?
						  // => 원인과 해결책은 다음 소스에서.. 
}
