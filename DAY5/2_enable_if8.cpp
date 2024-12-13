#include <iostream>
#include <type_traits>

// enable_if 기술
// => C++20 나오기 전까지 아주 널리 사용되었습니다.
// => 정확히 이해 하면 그렇게 어려운 기술도 아닙니다. (SFINAE 를 잘 활용한것)
// => 그런데, 코드가 복잡해 보입니다.

// 그래서, C++20 에는 "requires clauses" 라는 문법이 도입됩니다.
// => enable_if 라는 테크닉을 "문법으로 발전" 시킨것. 
// => 아래 코드 빌드하려면 "C++버전 20" 으로 설정해야 합니다.

template<typename T> requires std::is_pointer_v<T>
void printv(const T& v)
{
	std::cout << "포인터인 경우\n";
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v)
{
	std::cout << "포인터가 아닌 경우\n";
	std::cout << v << std::endl;
}


int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}