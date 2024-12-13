#include <iostream>

// recursive 유사 기술

// 1. 모든 인자를 "가변인자"로 하지 말고, 1번째 인자는 독립된 이름으로 받는다.
// 2. 함수 안에서 1번째 인자 사용하고, 
// 3. recursive 와 유사하게 foo(args...) 사용

// 주의!! 아래 코드는 "recursive" 처럼 보이지만 실제 recursive 는 아닙니다.
// 아래 같이 호출되는 것
// main => foo(int, double, char) => foo(int, double) => foo(int) => foo()


void foo() {}	// 재귀 종료를 위해서 인자 없는 foo - C++11
				// 아래 코드에서 C++17 기술로 하면 이 함수 필요 없음. 

template<typename T, typename ... Types>
inline void foo(T value, Types ... args)
{
	std::cout << value << std::endl;

	// C++17 이전에는 아래 처럼
//	foo(args...); // foo(3.4, 'A')	=> value : 3.4,    args : 'A'
				  // foo('A')		=> value : 'A'     args : 
				  // foo() => 재귀 종료를 위해 인자 없는 foo 도 필요
			
	// C++17 부터는 아래 처럼 하면 됩니다.
	// => 인자 없는 foo() 가 필요 없습니다.
	// => if constexpr 이 기술이 C++17 부터 가능
	if constexpr ( sizeof...(args) > 0 )
		foo(args...);
				  		
}



int main()
{
	foo(1, 3.4, 'A');	// value : 1,   args : 3.4,  'A'
}





