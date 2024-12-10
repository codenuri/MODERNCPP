#include <iostream>
#include <vector>

// noexcept 이야기 - 103 page

class Object
{
public:
	Object() = default;

	Object(const Object&) 
	{	
		std::cout << "copy" << std::endl;	
	}
	
	// move 생성자의 구현은 대부분 메모리 자체를 복사하지 않고
	// 포인터만 복사하고, 원본 포인터를 0 으로 reset 하는 정도의 일만 하게 됩니다.
	// => 이런 작업에는 예외가 발생할 가능성이 없습니다.
	// 따라서, move 생성자를 만들때는 반드시 예외가 없다고 표기하는 것이 좋습니다.
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1;				// 항상 복사 생성자 사용
	Object o3 = std::move(o1);	// 항상 이동(move) 생성자 사용
	Object o4 = std::move_if_noexcept(o2); 
						// move 생성자에 예외가 없다면(noexcept가 붙었다면) move 생성자사용
						// 그렇지 않다면 복사 생성자 사용


	std::vector<Object> v(3);

	std::cout << "----------------" << std::endl;

	v.resize(5); // 이순간의 원리를 생각해봅시다.
				// 기존 버퍼 요소 => 새로운 버퍼로 이동 할때
				// => std::move_if_noexcept() 사용합니다.

	std::cout << "----------------" << std::endl;
}

