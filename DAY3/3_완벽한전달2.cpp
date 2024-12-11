#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }


// 완벽한 전달을 하려면
// 1. 복사본을 만들면 안되고
// 2. 상수성도 추가되면 안된다.
// => 결국, int&, int&& 의 버전을 각각 제공해야 한다.

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
	int n = 10;

	chronometry(foo, 10); 
	chronometry(goo, n); 

	std::cout << n << std::endl;
}
