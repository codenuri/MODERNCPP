#include <iostream>
// 약간 어려운 이야기 입니다.

class CompilerGeneratedName
{
public:
	inline  int operator()(int a, int b) const { return a + b; }

	// 함수 포인터로의 변환을 지원하기 위해서 operator() 와 같은 일을 하는
	// static 멤버 함수가 한개 더 있어야 합니다.
	static int helper(int a, int b) { return a + b; }


	// 변환 연산자 함수 : 객체가 다른 타입으로 변환되어야 할때 호출
	// int  n = 객체; // 객체.operator int()
	// char n = 객체; // 객체.operator char()
	// 함수포인터 f = 객체; // 객체.operator 함수포인터타입()

	using F = int(*)(int, int);

//	operator F() { return 함수주소; }
//	operator F() { return &CompilerGeneratedName::operator();} // error.
							//        멤버 함수는 일반 함수 포인터와 호환 안됩니다.
							// static 멤버 함수는 일반 함수 포인터와 호환 됩니다.

	operator F() { return &CompilerGeneratedName::helper; } 
};


int main()
{
	int(*f)(int, int) = CompilerGeneratedName{};
					 // 이순간 "객체.operator 함수포인터타입()" 이라는 멤버함수호출 

	int n = f(1, 2);

	std::cout << n << std::endl;


	// 람다 표현식을 함수 포인터에 담아서 사용할수 있습니다.
//	int(*f)(int, int) = [](int a, int b) {return a + b; };
						// 임시객체
//	int n = f(1, 2);
}












