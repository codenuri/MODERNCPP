#include <iostream>
#include <type_traits>

// 아래 한글부분 코드로 변경해 보세요 - std::is_pointer 사용

template<typename T> void printv(const T& v)
{
	if (T 가 포인터 타입 이면)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

