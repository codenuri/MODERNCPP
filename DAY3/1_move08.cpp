#include <iostream>
#include <string>

// move 계열함수 에서는 모든 멤버를 move로 옮겨라! - 102 page

class Cat
{
	char* name;
	int   age;
	std::string address;
public:
	Cat(const char* n, int a, const std::string& address) : age(a), address(address)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}

	~Cat() { delete[] name; }




	Cat(const Cat& c) : age(c.age), address(c.address)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}

	Cat(Cat&& c) noexcept 
		: age(c.age), 
		  name(c.name),
//		  address(c.address)  // 잘못된 구현, string 복사 생성자 호출, 문자열 복사됨.
		  address( std::move(address))  // 핵심. move 생성자에서는 모든 멤버를 move 로 옮겨라
										// 단, int 같은 primitive 멤버는 그냥 복사해도 된다.
	{
		c.name = nullptr;
	}

};

int main()
{
	Cat c1("nabi", 2, "seoul");

	Cat c2 = std::move(c1);

}





