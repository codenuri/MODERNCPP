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
	
	// move 지원 setter 만들기

	// 방법 #1. 2개의 setter 
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n) { name = std::move(n); }

	// 방법 #2.
};

int main()
{
	People p;

	std::string s1 = "kim";
	std::string s2 = "lee";

	p.set_name(s1);				
	p.set_name(std::move(s2));	


}








