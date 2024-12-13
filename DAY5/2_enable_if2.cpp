#include <iostream>
#include <type_traits>

// 핵심 
// static_assert : 조건을 만족하지 않은 경우, 무조건 에러!!

// 조건을 만족하지 못할때, 에러가 아니라
// => 후보에서 제외 할수 없을까 ???
// => SFINAE 와 enable_if 를 사용하면 됩니다.

// 최대 공약수를 구하는 것을 생각해 봅시다.
template<typename T> T gcd(T a, T b)
{
	static_assert(std::is_integral_v<T>, "error, not integer");

	return 0;
}

double gcd(double a, double b)
{
	std::cout << "double\n";
	return 0;
}

int main()
{
	gcd(6, 9);		 // T
	gcd(3.1,  5.4);	 // double 사용
	gcd(3.1f, 5.4f); // T 버전 사용, static_assert 에서 실패. error
}
