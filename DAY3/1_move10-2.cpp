#include <iostream>
#include <string>

// 자동 생성 규칙.
// 규칙 #3. 사용자가 이동생성자만 제공한 경우
// => 컴파일러는 복사 생성자를 제공하지 않습니다.(정확히는 삭제(delete) 합니다)
// => 이경우, 복사 생성자가 필요한 코드가 있다면 컴파일 에러!!
// move 생성자가 대신 복사 생성자를 사용할수 있지만
// 복사 생성자가 대신 이동 생성자를 사용할수는 없다.

// 이 경우도, 복사 생성자를 "=default" 로 요청할수는 있습니다.

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

	Object o3 = o1;	// error
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; 
	std::cout << o2.name << std::endl; 
}
