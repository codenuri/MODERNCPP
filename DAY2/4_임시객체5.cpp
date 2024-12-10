#include <iostream>
// 85 page

struct Base
{
	int value = 10;
};

struct Derived : public Base
{
	// 기반 클래스와 동일한 이름의 멤버를 추가해도 
	// 문제 없습니다.
	int value = 20;
};

int main()
{
	Derived d;

	std::cout << d.value << std::endl; // 20   Derived에서 추가된 value

	// 기반 클래스로 부터 상속받는 value 에 접근하려면 캐스팅하면 됩니다.
	std::cout << static_cast<Base&>(d).value << std::endl; // 10 
	std::cout << static_cast<Base>(d).value << std::endl; // 10 

	// static_cast<Base&>(d) : d 를 Base 처럼 해석해 달라는 의미. 
	// static_cast<Base>(d)  : d 를 복사해서 새로운 Base 객체 생성(임시객체)

	static_cast<Base&>(d).value = 30; // ok
	static_cast<Base>(d).value = 30; // error.   "임시객체.value = 30" 의미
}

// 정리 : 임시객체는

// 1. 개발자가 의도적으로 만들기도 하고 ( 주로 함수 인자로 사용 )
// => draw_line( Point{0, 0}, Point{9, 9});

// 2. 개발자가 만든 코드 때문에 임시객체가 생성되기도 합니다.
// => 객체를 값으로 반환하는 함수   Point foo() { return pt; }
// => 값 타입으로 캐스팅 할때       static_cast<Base>(d).value 

