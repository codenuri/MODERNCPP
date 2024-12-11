// C++11 에 추가된 기술중 가장 중요한것들(창시자가 선택한)
// 1. move semantics
// 
// 2. perfect forwarding
// 
// 3. lambda expression - 
//		=> 1. 함수객체를 먼저 이해하고
//		=> 2. lambda expression 를 학습해야 
//		완벽히 이해할수 있습니다.
// 
// 4. variadic template
// ....



#include <iostream>

// function object(함수 객체, functor 라고도 합니다)
// => () 연산자를 재정의 해서 함수 처럼 사용가능한 객체

// 왜 ?? 일반 함수를 사용하면 되는데, 함수객체를 사용하나요 ?
// => 함수 객체가 "일반 함수"보다 훨씬 좋습니다
// => C++20 부터 새롭게 추가된 함수는 대부분 일반 함수가 아니라 함수객체 입니다.

// 1. 상태를 가지는 함수
// 2. closure
// 3. 특정 상황에서 함수 보다 함수객체가 빠르다
// 4. 자신만의 타입을 가지는 함수
// .... 의 장점이 많습니다



struct Plus
{
	int operator()(int a, int b) 
	{
		return a + b;
	}
};


int main()
{
	Plus p;	// p 는 "Plus" 라는 타입의 "객체" 입니다. "함수"는 아닙니다.

	int n1 = p(1, 2);	// 객체(변수)인 p를 "함수 처럼 사용" 합니다.
						// 함수 객체 라고 합니다.

	int n2 = p.operator()(1, 2); // 위 코드는 컴파일러에 의해서 
								 // 이 코드로 변경 됩니다.
								 // 이렇게 직접 호출해도 됩니다.

	// "a + b" 에서 a 가 사용자 정의 타입의 객체라면
	// "a.operator+(b)" 라고 해석됩니다. 연산자 재정의 문법 
					
	
}
