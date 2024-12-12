#include <iostream>

class CompilerGeneratedName
{
	int v1;
	int v2;
public:
	CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

	inline  int operator()(int a, int b) const { return a + b + v1 + v2;} // ok


	// 위와 동일한 일을 하는 static 멤버 함수를 만들어야 하는데..
	// 문제는 static 멤버 함수에서는 멤버데이타인 v1, v2 를 접근할수 없습니다.
	// 따라서, 아래 함수를 생성해 낼수 없습니다.
	// => 그래서 함수 포인터로의 변환을 지원하지 않습니다.
	static int helper(int a, int b) { return a + b + v1 + v2; } // error


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
	int(*f2)(int, int) = [v1, v2](int a, int b) {return a + b + v1 + v2; }; // error
}

// 1. 간단한 문법 변화/추가
// 2. 타입추론, 초기화
// 3. move 이야기들, lvalue/rvalue, rvalue reference
// 4. perfect forwarding, forwarding reference
// 5. lambda expression, function object(함수객체)
// -----------------------------------------------
// 6. traits 기술, 사전지식 : 부분특수화, enable_if = template 관련










