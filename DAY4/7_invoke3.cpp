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

	return std::invoke(f, std::forward<T>(args)...);
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

// C++ 을 제대로 하려면

// 1. C++ 기본 문법 자체를 먼저 정확히 알아야 합니다.
// => 신기술, C++11, 14, 17, 그리고 20 등
// => C++20 부터 a < b 대신 a <=> b 를 사용합니다. 등
// => godbolt.org 로 각 문법의 원리를 정확히 알아야 합니다.

//-----------------------------
// 2. 디자인 패턴을 하세요 - 객체지향. OOP 이론..

// 3. 각 문법을 깊이 있게 해야 합니다. - C++ 중급
// => 생성자 하나만 제대로 해도.. 어렵습니다. 
// => new(&pt) Point(1,2) <= 이런 코드를 이해 해야 합니다.
// => trivial
// => callable 등의 개념

// 4. template 문법도 한번 정리할 필요 있습니다.
// => SFINAE, integral constant

// 5. STL 라이브러리 사용법
// => move iterator, counted iterator, reverse iterator등.. 
// => 아주 많은 라이브러리가 있습니다.

// 6. Concurrent 라이브러리.. 

// 필독
// => effective C++ 시리즈, effective modern C++..





