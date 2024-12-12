// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// "지역변수 캡쳐" 라는 문법의 정확한 원리

//	auto f1 = [v1, v2](int a) { return a + v1 + v2; };  // ok
//	auto f1 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; // error.
																 // operator()가 상수함수인데
																 // 값을 변경하고 있기때문
																 // 아래 원리 참고
	// mutable lambda expression
	// => operator() 연산자를 non-const member function 으로 해달라는 의미.
	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; };


	f1(0);	// f1.operator()(0) 으로 호출
			// v1 = 100 이 실행되지만 
			// main 의 지역변수 v1 이 변경된것이 아니라
			// 복사본(아래 클래스에서 멤버데이타 v1) 이 변경된것 입니다.

	std::cout << v1 << std::endl; // 10


	std::cout << sizeof(f1) << std::endl; // 8. 결국 아래 클래스의 크기
										  //    int v1, v2 가 멤버 데이타 이므로



	
	// 위 한줄을 보고 컴파일러는 아래 코드를 생성합니다.
	class CompilerGeneratedName
	{
		int v1;	// 지역변수 캡쳐 문법을 사용하면 
		int v2; // 멤버 데이타가 추가됩니다.
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

//		inline auto operator()(int a) const		// 일반 람다 표현식
		inline auto operator()(int a)			// mutable 람다 표현식
		{ 
			v1 = 100; 
			return a + v1 + v2; 
		}
	};
	auto f2 = CompilerGeneratedName{ v1, v2 }; // 여기서 v1, v2 는 main 함수 인자
}





