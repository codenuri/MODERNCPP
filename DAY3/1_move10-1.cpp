#include <iostream>
#include <string>

// 자동 생성 규칙.
// 규칙 #2. 사용자가 복사생성자만 제공한 경우
// => 컴파일러는 이동계열의 함수를 제공하지 않습니다

// => std::move() 사용시, 사용자가 만든 복사 생성자 호출. 

struct Object
{
	std::string name;

	Object() = default;
	//-------------------------------	
	Object(const Object& other) : name(other.name)
	{
		std::cout << "copy\n";
	}
};



int main()
{
	Object o1; o1.name = "object#1";
	Object o2; o2.name = "object#2";

	Object o3 = o1;
	Object o4 = std::move(o2); // 컴파일러가 만든 move 생성자 없으므로
							   // 사용자가 만든 복사 생성자 사용

	std::cout << o1.name << std::endl; // "object#1"
	std::cout << o2.name << std::endl; // "object#2"
}
