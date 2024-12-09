// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept ( C++11 )
// #1. 함수가 예외가 있는지 없는지 조사
// #2. 함수가 예외가 없음을 알리기 위해 사용

void foo() 
{
}
void goo()
{
}

int main()
{
	// 사용법 : noexcept(함수 호출식) => 함수 가 예외가능성이 있는지 조사
	//								 => 함수가 실제 호출되는 것은 아니고
	//								 => 컴파일 시간에 조사만.
	bool b1 = noexcept( foo() );
	bool b2 = noexcept( goo() );

	std::cout << b1 << ", " << b2 << ", " << std::endl;
}




