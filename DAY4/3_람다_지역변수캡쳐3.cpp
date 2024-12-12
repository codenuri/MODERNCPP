// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;


//	auto f1 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; };		// error
	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; };




	class CompilerGeneratedName
	{
		int v1;	
		int v2; 
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

//		inline auto operator()(int a) const		
		inline auto operator()(int a)			
		{
			v1 = 100;
			return a + v1 + v2;
		}
	};
	auto f2 = CompilerGeneratedName{ v1, v2 }; 
}





