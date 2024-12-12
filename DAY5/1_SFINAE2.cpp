#include <iostream>

// SFINAE
// => Sustitution Failure Is Not An Error
// => 치환 실패는 에러는 아니다.

// 함수 템플릿을 사용하기로 결정하고, T의 타입이 결정된 상태로
// 함수를 생성할때 실패를 하게 되면(아래 예제)
// 에러가 아니라 호출 후보에서 제외 된다.
// 동일이름의 다른 함수가 있으면 사용될수 있다.

template<typename T>
typename T::type foo(T a)   { std::cout << "T" << std::endl; return 0; }
//     int::type foo(int a) {  ..... }

int foo(...) { std::cout << "..." << std::endl; return 0; }

int main()
{
	// 함수 호출시 어떤 함수를 호출할것인가는 
	// 리턴 타입이 아닌 "인자의 모양을 가지고 결정"
	foo(3); // template 버전을 선택!
			// T=int 로 결정하고, 
			// 함수를 생성하려면 시도
}
