#include <iostream>
#include <type_traits>

// enable_if 를 사용한 반환 타입 만들기


// 사용법 : enable_if< 조건, 반환타입 >::type
// => 아래 코드는 결국 조건을 만족(정수계열 타입)하는 경우만 gcd 템플릿을
//    사용하겠다는 것

template<typename T> 
						//  true 라면			  T
typename std::enable_if< std::is_integral_v<T>, T>::type
						//  false 라면			 "::type" 없음. 
gcd(T a, T b)
{

	return 0;
}



double gcd(double a, double b)
{
	std::cout << "double\n";
	return 0;
}

int main()
{
	gcd(6, 9);		 
	gcd(3.1, 5.4);	
	gcd(3.1f, 5.4f); 
}
