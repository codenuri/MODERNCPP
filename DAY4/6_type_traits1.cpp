// 4_type_traits - 184page

#include <iostream>

// 아래 함수를 완성하려면 템플릿 인자 "T" 가 포인터 인지 조사할수 있어야 합니다.
// => 다음 소스에서 해결
template<typename T> void printv(const T& v)
{
	if ( T 가 포인터 타입 이면 )
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

