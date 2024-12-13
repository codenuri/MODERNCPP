#include <functional> // std::invoke

class Object
{
public:
	// Object obj;
	// obj.f1(10) 의 원리는 컴파일러가
	// f1(&obj, 10) 로 변경하는 것입니다.

	void mf1(int code) {}  // void f1(Object* this, int code) {}

	static void mf2(int code) {} // this 가 추가되지 않은 멤버 함수. 
};

void foo(int n) {}

int main()
{
	void(*f1)(int) = &foo;		  
	void(Object::*f2)(int) = &Object::mf1; 

	Object obj;

	// #1. 일반 함수 포인터와 멤버 함수 포인터는 사용법이 다릅니다.
	f1(10);			// 일반 함수 포인터 사용
	(obj.*f2)(10);	// 멤버 함수 포인터 사용


	// #2. 위 문제를 해결하기 위해 C++ 창시자가 아래 문법을 제안했습니다.
	// => "uniform call syntax" 라는 문법
	// => 그런데, 표준에 채택 안됨.
//	f1(10);
//	f2(&obj, 20); // obj.f2(20)


	// #3. 대신 C++17 에서 std::invoke 라는 라이브러리를 추가하게 됩니다.
	// => #include <functional> 필요
	std::invoke(f1, 10); // f1(10)
	std::invoke(f2, &obj, 10);	// obj.f2(10)
}
