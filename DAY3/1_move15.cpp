#include <iostream>
#include <string>
#include <vector>
#include <array>

// 핵심 : Setter 만들기 #3

class People
{
private:
	std::string name;
	std::string address;
public:
	// 인자가 2개인 setter 의 move 지원
	void set(const std::string& n, const std::string& a)
	{
		name = n;
		address = a;
	}

	void set(std::string&& n, std::string&& a)
	{
		name = std::move(n);
		address = std::move(a);
	}

	void set(std::string&& n, const std::string& a)
	{
		name = std::move(n);
		address = a;
	}

	void set(const std::string& n, std::string&& a)
	{
		name = n;
		address = std::move(a);
	}

	// 핵심
	// => 인자가 2개인 setter 를 move 지원하게 하려면 "4개 함수" 를 만들어야 합니다.
	// => 인자가 N개인 setter 를 move 지원하게 하려면 "2^n 개 함수"를 만들어야 합니다.
	
	// "생성자" 도 결국 setter 입니다.
	// => 인자가 3개인 생성자를 move 지원 하려면 "8개 생성자" 필요 합니다.

	// 너무 많습니다.. 좋은 방법이 없을까요 ?
	// => forwarding reference 와 완벽한 전달을 배운후, 적용하면 간단해 집니다.

};

int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p;
	p.set(name,			   addr);
	p.set(std::move(name), addr);
	p.set(name,			   std::move(addr));
	p.set(std::move(name), std::move(addr));
}








