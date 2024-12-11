#include <iostream>
#include <string>
#include <vector>

// 핵심 : Setter 만들기 #1

class People
{
private:
	std::string name;
	int age;

public:
	// 방법 1. call by value
	// => std::string 의 복사본을 만드는 것은 너무 오버헤드가 많습니다.
	// => 절대 사용하지 마세요!!
//	void set_name(std::string n) { name = n; }

	// 방법 2. call by const reference
	// => C++98 시절이라면 최선의 코드!!!
	// => C++11 이후부터는 "최선은 아님"
	void set_name(const std::string& n) { name = n; }
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);
	p.set_name(std::move(s2));	

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""

}








