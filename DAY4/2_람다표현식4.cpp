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

	// 결국 위코드는
	/*
	auto f = 임시객체; 인데
	Point pt = Point(1, 2); // 에서. 최적화에 의해서
	Point pt(1, 2);			// 가 됩니다. 그래서 위코드는
	xxx f;					// 즉, f 는 컴파일러가 만든 타입의 객체를 생성한것
	*/

	int n1 = f(1, 2);			 // 3. f를 함수 처럼 사용하면 됩니다.
	int n2 = f.operator()(1, 2); // 이렇게도 사용가능합니다. 함수 객체 이므로!!

	//-----------------------------
	// 아래 코드에서 에러를 모두 찾으세요
	auto  f1	   = [](int a, int b) { return a + b; };	// ok
	auto& f2	   = [](int a, int b) { return a + b; };	// error
	const auto& f3 = [](int a, int b) { return a + b; };	// ok
	auto&& f4	   = [](int a, int b) { return a + b; };	// ok

	// 위 코드에는 f1 이 가장 좋은 코드
	Point pt = Point(); // 의미 인데. 최적화 되므로
	Point pt;           // 입니다. overhead 전혀 없습니다.

	const Point& pt = Point(); // 는 결국 pt가 포인터 입니다.
							   // 따라서 pt를 사용할때 주소를꺼내서 접근
							   // 하므로 약간의 성능 저하 발생
}

