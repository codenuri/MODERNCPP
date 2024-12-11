#include <iostream>
#include <string>
#include <vector>

// �ٽ� : Setter ����� #1

class People
{
private:
	std::string name;
	int age;

public:
	
	// move ���� setter �����

	// ��� #1. 2���� setter 
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n) { name = std::move(n); }

	// ��� #2.
};

int main()
{
	People p;

	std::string s1 = "kim";
	std::string s2 = "lee";

	p.set_name(s1);				
	p.set_name(std::move(s2));	


}








