#include <iostream>
#include <algorithm>
#include <functional>

// 람다 표현식의 원리 - 140p

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };



	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; } );


	// 위 한줄은 컴파일러에 의해 아래 처럼 변경됩니다.
	class CompilerGeneratedName
	{
	public:
		inline auto operator()(int a, int b) const 
		{
			return a < b; 
		}
	};

	std::sort(v.begin(), v.end(), CompilerGeneratedName{} );
}
// lambda expression
// => 이름에서 알수 있듯 "expression(표현식)" 입니다.
// => 표현식은 "한개의 값" 을 만드는 코드 집합..
// => 람다 표현식이 만든 한개의 값은 "컴파일러가 생성한 클래스의 임시객체" 입니다.

// 사실 C++에서는 lambda expression 문법이 없어도 됩니다.
// => 사용자가 직접 함수 객체를 만들어서 사용하면 되므로!!
// => 단지, 함수 객체를 편하게 만들기 위한 문법 입니다.



