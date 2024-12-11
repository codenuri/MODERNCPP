// 완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// forwarding : 전달 받은 인자를 다른 곳에 전달하는 것
// perfect forwarding : forwarding 할때 어떠한 변화도 없이 그대도 전달하는 기술


// 함수의 성능을 측정하는 함수
template<typename F>
void chronometry(F f, const int& arg)
{
	// 시간 측정해서 기록해 놓고

	f(arg);	// 함수 호출
	
	// 다시 시간 측정해서 수행시간 출력
}

int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10) 의 시간을 측정해 달라.
	chronometry(goo, n);  // goo(n) 의 시간을 측정해 달라.

	std::cout << n << std::endl;
}
