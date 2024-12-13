#include <iostream>
#include <functional>

class Test
{
public:
	void mf(int n, double d) {}
};

void foo(int n, double d) {}


template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... args)
{
	// stop_watch sw(true);

//	return f(std::forward<T>(arg)...);  // 이렇게 하면 f 가 일반 함수 포인터는 문제 없지만
										// 멤버 함수 포인터 라면 error 입니다.

	return std::invoke(f, std::forward<T>(arg)...);
				// 이렇게 해야, main 함수 처럼
				// 일반함수, 멤버 함수가 모두 가능합니다.
}

int main()
{
	chronometry(&foo, 1, 3.4);	// foo(1, 3.4) 의 소요 시간 측정

	// 멤버 함수는 "함수 주소와 객체주소, 인자들"을 전달
	Test test;
	chronometry(&Test::mf, &test, 1, 3.4); // test.mf(1, 3.4) 의 소요시간 측정
}