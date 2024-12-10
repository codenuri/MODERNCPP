#include <iostream>

// std::move() - 100 page

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
		std::cout << "복사" << std::endl;
	}

	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}
};
Cat foo()
{
	Cat c("yaong", 3);
	return c;
}
int main()
{
	Cat c1("nabi", 2);
	
	Cat c2 = c1;		// c1 은 lvalue, 복사 생성자 호출
	
	Cat c3 = foo();		// foo() 반환값은 임시 객체(rvalue), move(이동) 생성자 호출

	Cat c4 = static_cast<Cat&&>(c2);	// 캐스팅을 통해서 lvalue => rvalue 로 변경
										// "복사가 아닌 이동생성자" 호출

	Cat c5 = std::move(c3); // C++ 표준 함수인 std::move 가 하는 일이 위와 같은 캐스팅을 하는것

	// 핵심 : std::move 가 자원을 이동하는 것 아닙니다!!!!!

	// => 단지, std::move()는 인자로 전달된 객체를 rvalue 로 캐스팅 할뿐입니다.
	// => 캐스팅의 결과를 복사 생성자가 아닌 move 생성자가 호출되고, 
	// => move 생성자에서 자원을 이동하는 것..!!

	// 즉, 아래 코드는 결국 std::string 의 move 생성자가 호출된것!!!
	// => std::string class 를 만들때 move 생성자를 만들지 않으면 move 효과 없음.
	std::string s1 = "to be or not to be";
	std::string s2 = std::move(s1); // static_cast<std::string&&>(s1);

	// 결국 move 개념은 "std::move()" 에서 이동하는 것이 아니라ㅏ.
	// => 해당 클래스를 만든 사람이 "move 생성자"를 만들어야만 지원되는 것. 
}




