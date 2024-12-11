#include <iostream>
#include <string>
#include <vector>
#include <array>

// 핵심 : Setter 만들기 #2

class People
{
private:
	std::string name;
	int age;
	std::array<int, 32> data;
public:
	// setter 라는 것은 전달 받은 인자를 객체의 멤버 데이타에
	// 보관하게 됩니다
	// 이런것은 "retain" 한다 라고 합니다
	// 이런 경우만 "복사"와 "이동"을 고려하면 됩니다.
	// => 아래 처럼 2개 만드세요
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }


	// 아래 함수는 인자를 객체가 보관하는 것이 아니라
	// 함수 내부적으로 "사용"만 하게 됩니다.
	// 이런경우는 move 고려할필요 없습니다. 아래 처럼 한개만 만들면 된다.
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}

	// 아래 코드는 setter 지만, 
	// std::array<int, 32> 타입은 모든 데이타를 stack 에 관리하는 타입입니다
	// 따라서, array<int, 32> 는 std::move 효과 없습니다.
	// => 따라서, move 버전 만들필요없습니다.
	void set_data(const std::array<int, 32>& d)
	{
		data = d;
	}
};

int main()
{
	People p;
	std::string s = "hello";
	
	p.set_name(s);


	std::array<int, 32> arr = {0};

	

	p.print_msg(s);
	p.set_data(arr);
}








