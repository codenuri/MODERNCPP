int main()
{
	// generic lambda
	// => 인자로 auto 를 사용하는 것
	// => C++14 부터 지원
	auto f = [](auto a, auto b) { return a + b; };

	int    n = f(1, 2);
	double d1 = f(3.2, 3.2);
	double d2 = f(1,   3.2);
	double d3 = f(3.2, 1);
}
// generic 람다의 원리.
// => operator() 를 template 으로 만드는 것
// => 핵심 2개의 인자가 서로 다른 템플릿 인자를 사용하는 것
class CompilerGeneratedName
{
public:
	template<typename T1, typename T2>
	inline auto operator()(T1 a, T2 b) const
	{
		return a + b;
	}
};

// 생각해 볼문제
// => 일반 함수도 인자로 auto 사용가능할까요 ?
// => C++20 부터 가능합니다.
// => 원리는 템플릿 입니다.
void foo(auto n)		// template<typename T> void foo( T n)
{						// {
}						// }

// 그래서 C++20 부터는 add 를 template 으로 만들때 아래 처럼 합니다.
auto add(auto a, auto b) // template<typename T1, typename T2> auto add(T1 a, T2 b)
{
	return a + b;
}