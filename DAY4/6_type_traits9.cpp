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
T&& xmove(T&& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	Object o1;

	Object o2 = std::move(o1);
	Object o3 = std::move(Object{}); 
	// 아래 코드는 모두 move 나와야 합니다 그런데..
	// => 이유와 해결책은 다음소스에서.. 
	Object o4 = xmove(o2);			// copy
	Object o5 = xmove( Object{} );	// move
}
