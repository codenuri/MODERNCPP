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
	// 인자가 2개인 setter 의 move 지원하려면 직접 만드는 경우 아래 4개 필요
	/*
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
	*/

	// 인자가 2개 이상이 setter 의 move 지원은 는 T&& 기술로 만드는 것이 좋습니다.
	// 아래 템플릿이 위 4개의 모든 함수를 자동생성합니다.
	template<typename T1, typename T2>
	void set_name(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}

	// 생성자도 결국 setter 입니다.
	// 아래 코드는 move 지원이 안되는 생성자
//	People(const std::string& n, const std::string& a) : name(n), address(a) {}

	// 생성자도 아래 처럼 해야 move 지원 됩니다.
	template<typename T1, typename T2>
	People(T1&& n, T2&& a) 
		: name( std::forward<T1>(n) ), address( std::forward<T2>(a) ) {}

};

int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

//	People p;
	People p(name, std::move(addr));

	p.set(name, addr);
	p.set(std::move(name), addr);
	p.set(name, std::move(addr));
	p.set(std::move(name), std::move(addr));
}








