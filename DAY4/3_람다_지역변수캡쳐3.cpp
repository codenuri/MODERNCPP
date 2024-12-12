// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// #1. Capture by value
	// => 지역변수 v1, v2 의 복사본을 보관하게 됩니다.( 2.cpp 소스 참고)
//	auto f1 = [v1, v2](int a)         { v1 = 100; return a + v1 + v2; }; // error
	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; };


	// #2. Capture By Reference
	auto f2 = [&v1, &v2](int a) { v1 = a; v2 = a; };

	f2(100); // v1 = 100, v2 = 100 이 실행되는데, 
			 // 복사본이 아닌 main 의 지역변수를 변경

	std::cout << v1 << ", " << v2 << std::endl; // 100, 100


	class CompilerGeneratedName
	{
		int& v1;	
		int& v2; 
	public:
		CompilerGeneratedName(int& a, int& b) : v1(a), v2(b) {}

		inline auto operator()(int a) const		
		{
			v1 = a;		// ??? const member function 에서는 멤버데이타 수정 안되지 않나요 ??
						// v1은 int 가 아닌 int& 입니다.
						// int& 는 결국 컴파일 하면 int* 입니다
						// 즉, 이코드는
						// (*v1) = a; 라는 의미 입니다.
						// v1 자체의 변경이 아니라 v1 이 가리키는 곳의 변경입니다.
			v2 = a;
		}
	};
	auto f3 = CompilerGeneratedName{ v1, v2 }; 
}





