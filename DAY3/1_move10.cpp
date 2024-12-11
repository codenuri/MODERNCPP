#include <iostream>
#include <string>

// 자동 생성 규칙.
// 규칙 #1. 사용자가 복사 계열(복사 생성자, 대입연산자) 와
//					이동 계열(이동 생성자, 이동 대입연산자)를 모두 만들지 않으면
//			컴파일러가 모두 제공한다.

// 컴파일러가 제공하는 복사계열에서는
// => 모든 멤버를 복사합니다.

// 컴파일러가 제공하는 이동계열에서는
// => 모든 멤버를 이동합니다.
// => noexcept 로 만들게 됩니다.

// 따라서, 아래 코드는 복사와 이동을 완벽히 지원하는 클래스 입니다.
struct Object
{
	std::string name;

	Object() = default;
	//-------------------------------	
	// 아래 코드가 컴파일러가 자동생성한 코드의 원리
	// 복사 계열 2개
	/*
	Object(const Object& other) : name(other.name) {}

	Object& operator=(const Object& other)
	{
		if (this == &other) return *this;
		name = other.name;
		return *this;
	}
	// 이동 계열 2개
	Object(Object&& other) noexcept : name(std::move(other.name)) {}

	Object& operator=(Object&& other) noexcept
	{
		if (this == &other) return *this;
		name = std::move(other.name);
		return *this;
	}
	*/
};

int main()
{
	Object o1; o1.name = "object#1";
	Object o2; o2.name = "object#2";

	Object o3 = o1;
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; // "object#1"
	std::cout << o2.name << std::endl; // ""
}
