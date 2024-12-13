#include <iostream>
#include <functional>

class Test
{
public:
	void mf(int n, double d) {}
};

void foo(int n, double d) {}


template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... args)
{
	return f(std::forward<T>(arg)...);
}

int main()
{
	chronometry(&foo, 1, 3.4);

	chronometry(&Test::mf, 1, 3.4);
}