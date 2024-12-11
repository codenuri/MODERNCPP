// 105 page.. 상수 객체와 move
#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&)      { std::cout << "copy" << std::endl; }
	Object(Object&&) noexcept  { std::cout << "move" << std::endl;	}
};
int main()
{
	const Object o1;

	// 핵심 : 상수 객체는 move 될수 없습니다.
	//       아래 코드는 복사 생성자를 호출 합니다.
	Object o2 = std::move(o1);	
			// static_cast< o1의타입&& >(o1)
			// static_cast< const Objec&& >(o1)

	// Object&&      : non-const rvalue 만 받을수 있다.
	// const Object& : lvalue, const lvalue, rvalue, const rvalue 모두 받을수 있다.
	//				
}



