// 9_완벽한전달_주의사항
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)	// int&& arg = 0
{								// std::nullptr_t&& arg = 0

	f(std::forward<T>(arg));	// foo(arg) 에서 arg가 int&& 라면 에러
								// std::nullptr_t 이라면 에러 아님.
}

void foo(int* p) {}

int main()
{
	foo(0);				 // ok

//	chronometry(foo, 0); // error
	chronometry(foo,nullptr); // ok

	// 핵심 : 완벽한 전달 기술로 되어 있는 함수를 사용할때는
	//		  포인터의미로 0을 사용할수 없다.
	//		  nullptr 사용해야 합니다.
}









