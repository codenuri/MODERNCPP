// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// "지역변수 캡쳐" 라는 문법의 정확한 원리

	auto f1 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; 

	
	// 위 한줄을 보고 컴파일러는 아래 코드를 생성합니다.
	class CompilerGeneratedName
	{
		int v1;	// 지역변수 캡쳐 문법을 사용하면 
		int v2; // 멤버 데이타가 추가됩니다.
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

		inline auto operator()(int a) const 
		{ 
			v1 = 100; 
			return a + v1 + v2; 
		}
	};
	auto f2 = CompilerGeneratedName{ v1, v2 }; // 여기서 v1, v2 는 main 함수 인자
}





