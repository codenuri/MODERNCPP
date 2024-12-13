#include <iostream>
#include <type_traits>

// enable_if 기술은 아래 3곳에서 가능합니다.
// 1. 반환 타입 위치	=> 가장 널리 사용
// 2. 함수 인자 위치 => 코드가 좀 복잡해 보이게 되어서 잘 사용 안함
// 3. template 인자 위치 => 생성자 같이 반환 타입이 없는 경우 사용

template<typename T>
void printv(const T& v, std::enable_if_t<std::is_pointer_v<T>, int> a = 0 )
{
	std::cout << "포인터인 경우\n";
	std::cout << v << " : " << *v << std::endl;
}

template<typename T>
void printv(const T& v, std::enable_if_t<!std::is_pointer_v<T>, int> a = 0)
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