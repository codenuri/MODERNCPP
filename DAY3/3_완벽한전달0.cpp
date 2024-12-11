#include <iostream>

// 완벽한 전달0.cpp
// => 사전 지식

// 오버로딩 규칙 - 90p


void foo(int& a)  { std::cout << "1. int&" << std::endl; }
void foo(int&& a) { std::cout << "2. int&&" << std::endl; }

int main()
{
	int n = 10;
	foo(n);		// 1. int&
	foo(10);	// 2. int&&

	int& r1 = n;
	foo(r1);	// 1. int& 


	int&& r2 = 10;
	foo(r2);	// 1. int&

	// expression(표현식) : 하나의 값을 만드는 코드 집합
	// expression이 만들어내는 값은 2개의 속성이 있습니다.
	// => data type, value category

	int n = 0;
	Point pt(1, 2);

	// expression			type			value category
	// 10
	// n
	// pt
	// Point{0,0}
	// r1
	// r2
	//-------------------------------------------------------

}







