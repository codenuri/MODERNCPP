#include <iostream>
#include <string>

// 자동 생성 규칙.
// 규칙 #3. 사용자가 이동생성자만 제공한 경우

struct Object
{
	std::string name;

	Object() = default;
	//-------------------------------	
	Object(Object&& other) noexcept : name(std::move(other.name))
	{
		std::cout << "move\n";
	}

};

int main()
{
	Object o1; o1.name = "object#1";
	Object o2; o2.name = "object#2";

	Object o3 = o1;
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; // "object#1"
	std::cout << o2.name << std::endl; // ""
}
