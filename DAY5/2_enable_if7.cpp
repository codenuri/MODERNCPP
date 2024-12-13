#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	// move 를 지원하는 생성자 만들기
	template<typename T>
	People(T&& n) : name(std::forward<T>(n)) {}
};

int main()
{

	std::string s = "kim";
	People p1(std::move(s));

	People p2(3.4);

}