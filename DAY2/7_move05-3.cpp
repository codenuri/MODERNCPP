#include <iostream>
#include <cstring>

// std::move() - 100 page

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name,  n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name,  c.name);
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

	// 아래 코드는 이론상 "Cat c3 = 임시객체;" 이므로 이동 생성자가 호출되어야 합니다.
	// => 그런데, 대부분의 컴파일러는 "임시객체제거" 라는 최적화 기술을 사용하므로 
	// => 아래 코드는 임시객체가 없어서 "이동"이 나오지 않습니다.
	Cat c3 = foo();		

	// 이경우 확인하려면 "g++ 컴파일러사용하고, -fno-elide-constructors" 라는 옵션을 사용하세요
	// => 임시객체 제거 최적화 하지 말라.!


	// 복습 하실때

	// "g++ 소스이름.cpp -std=c++11  -fno-elise-constructors" 로 빌드하는데
	// #1. C++ 버전 -std=c++11 일때와  -std=c++17 일때 비교 하고
	// #2. -fno-elise-constructors 가 있을때와 없을때를 잘 비교해 보세요
	
}




