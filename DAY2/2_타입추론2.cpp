#include <iostream>

template<typename T> void foo(T a)
{
	a = 100;
}

int main()
{
	// 타입을 명시적으로 전달하는 경우
	// => 컴파일러가 타입을 결정하지 않고, 무조건 사용자가 전달한 타입사용
	foo<int>(3.4);

	// 사용자가 타입을 전달하지 않은 경우
	// => 함수 인자를 보고 컴파일러가 타입 결정
	// T의 타입을 예측해 보세요
	foo(10); // T : int
	foo(3.4);// T : double

	//------------------------------------	
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;
	
	foo(n); 
	foo(c); 
	foo(r); 
	foo(cr);
}
