#include <iostream>

// 추론된 타입을 확인하는 방법
// #1. godbolt.org 사용 => 가장 권장!!
// #2. 생성된 함수의 이름을 출력 => 역시 좋은 방법
// #3. RTTI 기술 사용 => 버그 있음. 사용하지 말것  

template<typename T> void foo(T a)
{
	a = 100;
}

int main()
{

	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);	// T = int
	foo(c); // T = int
	foo(r); // T = int
	foo(cr);// T = int 
}
