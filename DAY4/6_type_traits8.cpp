#include <iostream>
#include <type_traits>

struct Object
{
	Object() = default;
	Object(const Object&)     { std::cout << "copy\n"; }
	Object(Object&&) noexcept { std::cout << "move\n"; }
};

// std::move 구현
template<typename T>
T&& xmove(T& obj)
{
	return static_cast<T&&>(obj);
}


int main()
{
	Object o1;

	Object o2 = std::move(o1);	
	Object o3 = std::move(Object{}); // ok

	Object o4 = xmove( o2 ); 
//	Object o5 = xmove( Object{} );	// 되야 할까요 ? 안되야 할까요 ?
									// 임시객체는 std::move() 없어도 move되지만
									// std::move() 에 넣어도 되야 합니다.
									// 현재는 error.
									// 이유와 해결책은 다음소스에서
}
