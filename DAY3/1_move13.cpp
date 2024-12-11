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
	// => 아래 코드는 이동을 지원할수 없는 setter
	// p.set_name(s1);				
	// p.set_name(std::move(s2)); // 이렇게 사용해도 복사 됩니다.
//	void set_name(const std::string& n) { name = n; } // 항상 복사 되는 코드

	// 아래 처럼 만들면 어떨까요 ?
	// => 인자 n 이 const 이므로 "역시 항상 복사" 입니다.
//	void set_name(const std::string& n) { name = std::move(n); } // 항상 복사


	// 방법 3. 정답!!!
	// => move 를 지원하는 setter를 만들려면 "2개" 를 만들어라!
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				// s1의 자원(문자열)을 복사해 가라는 것
	p.set_name(std::move(s2));	// s2의 자원(문자열)을 이동해 가라는 것

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""


	// 참고, 아래 push_back 에서 마우스 오른쪽 버튼 누르고 "정의로 이동" 메뉴 선택하면
	// 구현 볼수 있습니다
	// 아래 처럼 2개의 구현이 있는 것을 볼수 있습니다.
	// push_back( const T& arg)
	// push_back( T&& arg)

	std::vector<std::string> v;

	v.push_back(s1);
	v.push_back(std::move(s1));
}








