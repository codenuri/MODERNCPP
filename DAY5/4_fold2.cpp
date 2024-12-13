#include <iostream>

// #1. unary  right fold : (args + ...)	    => E1+(E2+(E3+(E4+E5)))		 
// #2. binary right fold : (args + ... + 0) => E1+(E2+(E3+(E4+(E5+0))))  
// #3. unary  left fold  : (... + args)	    => (((E1+E2)+E3)+E4)+E5		 
// #4. binary left fold  : (0 + ... + args) => ((((0+E1)+E2)+E3)+E4)+E5  


// 핵심 : pack 의 이름 뿐 아니라 pack 을 사용하는 표현식 자체를 사용 가능

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types>
void Show(Types ... args)
{
//	( printv(args)    ,        ... );
	// pack이름    이항연산자    ...   => (args + ...) 의 형태이므로 unary  right fold 
	//									E1+(E2+(E3+(E4+E5)))
	// printv(1) , ( printv(2), (printv(3), (printv(4) ,  ....... )
	// => fold expresson 은 아주 많은 일을 할수 있습니다

//	( std::cout << ... << args ); // 이 코드가 하는일은 ?
	// 초기값   op  ... op pack		이므로 binary left fold. ((((0+E1)+E2)+E3)+E4)+E5
	// (((((std::cout << e1) << e2) << e3 ) << e4 .... 
	// 결국 : std::cout << 1 << 2 << 3 << 4 ....


	// 아래 코드가 하는일은 ?
	( (std::cout << args << " ")  ,  ... );
	// pack 이름을사용하는표현색   op  ...   unary  right fold  => E1+(E2+(E3+(E4+E5)))
	// (std::cout << 1 << " "), ((std::cout << 2 << " "), ((std::cout << 3 << " ")

	// 핵심
	// 1. pack 이름만 사용가능한것이 아니라 pack 이름을 포함한 표현식도 가능
	// 2. 초기값은 0 같은 리터럴뿐아니라 std::cout 같은 객체도 가능
	// 3. 이항연산자는 연산자 재정의 되어 있는 것도 활용가능 ( << 연산자등)

}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}



