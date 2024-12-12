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





