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

	chronometry(foo, 10); // ok.. 아무 문제 없음.
	chronometry(goo, n);  // ok. 
						  // 그런데, 이 코드는 한가지 문제가 있습니다.
						  // => 다음 단계에서 설명.. 

	std::cout << n << std::endl;
}
