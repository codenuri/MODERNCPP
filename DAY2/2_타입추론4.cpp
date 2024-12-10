#include <iostream>

// template 규칙 정리!!


// 규칙 1. 값타입으로 받을때
//  함수인자의 "const, volatile, reference"제거후 T결정
//  T의 타입은 결국 a의 타입
template<typename T> void foo(T a)
{
	
}
// 규칙 2. 참조로 받을때
// 함수인자의 "reference" 제거후 T의 타입 결정
// const, volatile은 유지
// T가 결정되면 & 를 붙여서 a의 타입결정
// T가 int 라면 a는 int&

template<typename T> void goo(T& a)
{
}

// 규칙 3. forwarding reference => 가장 중요한데, 사전 지식이 필요합니다.(내일자세히)
// 인자가 lvalue 이면 T : lvalue reference
// 인자가 rvalue 이면 T : rvalue reference
template<typename T> void goo(T&& a)
{
}


int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);  // T : int
	foo(c);  // T : int
	foo(r);  // T : int 
	foo(cr); // T : int

	goo(n);  // T : int          a : int&
	goo(c);  // T : const int    a : const int&
	goo(r);  // T : int          a : int&
	goo(cr); // T : const int    a : const int&
}
