// 9_FOLD - 237 page

#include <iostream>

// Fold Expression : 가변인자 템플릿의 pack 안의 모든 요소에 이항 연산을 수행 - C++17


template<typename ... Types> 
int Sum(Types ... args)
{
	// arg 안에 있는 모든 요소의 합을 구하고 싶다.
	// args : 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 
	// 하고싶은일 : 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 
	// => pack 의 모든 요소에 이항연산자(+)를 적용하고 싶은것 

//	int n = (args + ...); // 이코드는 args 가 비었을때는에러 
						  // 1 + (2 + (3 + (4 + 5))))

	int n = (args + ... + 0); // args가 비었을때도 ok. 
								// 1 + (2 + (3 + (4 + (5 + 0))))

	return n;
}

int main()
{
//	int n = Sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	int n = Sum();

	std::cout << n << std::endl;
}






// fold expression
// => () 가 반드시 있어야 합니다.
// => 4개 종류가 있습니다.
// => '+' 위치에 어떠한 이항 연산자도 올수 있습니다.
// => '0' 위치에 어떠한 값(변수)도 올수 있습니다(init value 라고 합니다.)

//						   (pack이름  이항op  ...)
// #1. unary  right fold : (args + ...)	    => E1+(E2+(E3+(E4+E5)))		 
// #2. binary right fold : (args + ... + 0) => E1+(E2+(E3+(E4+(E5+0))))  
// #3. unary  left fold  : (... + args)	    => (((E1+E2)+E3)+E4)+E5		 
// #4. binary left fold  : (0 + ... + args) => ((((0+E1)+E2)+E3)+E4)+E5  

// fold expression
// => 함수 형 언어(haskell 같은)에서 만든 개념
// => C++ 외에, C#, python, java 등 대부분 언어에서 볼수 있습니다.