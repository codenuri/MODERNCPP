#include <iostream>
#include <type_traits>

struct Object
{
	Object() = default;
	Object(const Object&) { std::cout << "copy\n"; }
	Object(Object&&) noexcept { std::cout << "move\n"; }
};

// 함수 템플릿 만들때 아래 2개의 차이점을 명확히 알아 두세요
// 인자로 T&  사용 : lvalue 만 받겠다는 의도
// 인자로 T&& 사용 : lvalue, rvalue 모두 받겠다는 의도. 

// std::move() 는 
// => lvalue 와 rvalue 를 모두 받아서
// => rvalue 로 캐스팅 해서 반환

template<typename T>
constexpr std::remove_reference_t<T>&& xmove(T&& obj) noexcept 
{
	// 아래 코드는 항상 rvalue 로 캐스팅하는 것은 아닙니다.
	// xmove(o2) 인 경우 T = Object& 이고 T&& = Object& 이므로 아래 캐스팅은
	// static_cast<Object&>(obj) 입니다. 즉, lvalue 캐스팅 
//	return static_cast<T&&>(obj);


	// move 는 항상 rvalue 캐스팅 되어야 합니다.
	// 현재 문제는 "T안에 &가 포함" 되었다는것
	// 해결책은 T안의 모든 &를 제거한후 && 를 붙이면 됩니다.
//	return static_cast< typename std::remove_reference<T>::type &&> (obj);
	return static_cast< std::remove_reference_t<T>&&> (obj);
}

int main()
{
	Object o1;

	Object o2 = std::move(o1);
	Object o3 = std::move(Object{});

	Object o4 = xmove(o2);			// T = Object&,  T&& = Object&  static_cast<Object&>(obj)
	Object o5 = xmove(Object{});	
}
