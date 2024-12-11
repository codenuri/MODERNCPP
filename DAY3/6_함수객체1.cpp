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

// function object(함수 객체)
// => () 연산자를 재정의 해서 함수 처럼 사용가능한 객체

struct Plus
{
	int operator()(int a, int b) 
	{
		return a + b;
	}
};


int main()
{
	Plus p;		

	int n = p(1, 2);	
	
}
