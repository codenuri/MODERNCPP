// 7_가변인자템플릿8
#include <iostream>

void foo(int a, int b, int& c) { c = 100; }


// 가변인자 템플릿은 언제 사용하나요 ?
// => 전형적으로 사용되는 형태가 있습니다
// 1. std::tuple 같은 도구 만들때 - 오후에..
// 2. 완벽한 전달을 사용하는 기술에서 널리 사용됩니다
// => 전달받는 인자를 다른곳에 전달

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... args)
{
//	return f( std::forward<T>(arg...) ); //  std::forward<T>(e1, e2, e3)이므로 에러

	return f(std::forward<T>(arg)...); 
		 //f(std::forward<T1>(e1),std::forward<T2>(e2),std::forward<T3>(e3))
}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n); // foo(1, 2, n) 의 성능 측정

	std::cout << n << std::endl;
}

