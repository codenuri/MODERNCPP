// 9_완벽한전달_주의사항
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg));
}

void foo() {}
void foo(int a) {}
void foo(int a, int b) {}

int main()
{
	// 함수를 직접 호출시
	// => 인자를 보고 어느 함수인지 찾을수 있다.
	foo();
	foo(10);
	foo(10, 20);
 
//	chronometry(foo, 10); // error. 어떤 foo 인지 찾을수 없다.!!

	// 이 경우 아래 처럼 컴파일러가 찾을수 있게 힌트를 주면 됩니다.
	// => 아래 코드는 "void(*)(int)" 타입으로 캐스팅 가능한것을 사용 하겠다는것
	chronometry(static_cast<void(*)(int)>(foo), 10);
}









