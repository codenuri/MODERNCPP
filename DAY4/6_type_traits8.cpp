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

	Object o3 = xmove(o2); 
}
