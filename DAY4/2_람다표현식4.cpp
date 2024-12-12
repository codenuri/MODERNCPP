#include <iostream>

// auto 와 람다 표현식
int main()
{
	// 람다 표현식 활용
	// 
	// #1. std::sort(), std::find_if() 등의 알고리즘에 인자로 전달
	//		=> 결국 함수객체를 전달하는것이므로 "인라인 치환" 
	// 
	// #2. auto 변수에 담아서 함수 처럼 사용

	auto f = [](int a, int b) { return a + b; };
			 // class xxx{ operator()(...){}}; xxx{};

	int n1 = f(1, 2);			 // 3. f를 함수 처럼 사용하면 됩니다.
	int n2 = f.operator()(1, 2); // 이렇게도 사용가능합니다. 함수 객체 이므로!!
}

