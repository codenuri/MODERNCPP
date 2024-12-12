#include <iostream>

class CompilerGeneratedName
{
public:
	inline  int operator()(int a, int b) const { return a + b; }

	static int helper(int a, int b) { return a + b; }


	using F = int(*)(int, int);
	operator F() { return &CompilerGeneratedName::helper; }
};


int main()
{
	// #1. 캡쳐하지 않은 람다 표현식은 함수 포인터로 변환 됩니다.
	int(*f1)(int, int) = [](int a, int b) {return a + b; };	// ok


	// #2. 하지만 캡쳐한 람다표현식은 함수 포인터 변환 안됩니다.
	// => 왜 그럴까요 ? 
	// => 위 소스 참고 하세요
	int v1 = 0, v2 = 0;
	int(*f2)(int, int) = [v1, v2](int a, int b) {return a + b+v1+v2; }; // error
}












