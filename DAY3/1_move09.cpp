#include <iostream>

// rule of 5, 3

// 클래스 만들때 생성자에서 "동적 메모리 할당(자원 할당)" 하는 코드가 있다면

// C++98 : 아래 3개의 멤버 함수를 만들어야 합니다. - rule of 3
// => 자원 해지를 위해서 "소멸자" 필요
// => 얕은 복사를 해결하기 위해 "복사 생성자" 필요
// => 복사 생성자를 만든 경우 관례적으로 "대입연산자"도 필요


// C++11 : 이동(move) 개념을 지원하기 위해서 위 3개에 추가로 아래 2개를 만들어라!
//		   rule of 5
// => 이동생성자, 이동 대입연산자


class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}
	Cat& operator=(const Cat& c)
	{
		if (&c == this) return *this;

		age = c.age;

		delete[] name;

		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	
		return *this;
	}
	
	Cat(Cat&& c) noexcept : age(c.age), name(c.name)
	{
		c.name = nullptr;
	}

	Cat& operator=(Cat&& c) noexcept
	{
		if (&c == this) return *this;

		age = c.age;

		delete[] name;

		name = c.name;
		c.name = nullptr;

		return *this;
	}
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;	// 초기화, 복사 생성자 호출
	c2 = c1;		// 대입,   대입 연산자 호출

	Cat c3 = std::move(c1);	// 이동 생성자 호출
	c3 = std::move(c2);		// 이동 대입 연산자 호출. 

}




