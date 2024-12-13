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
	// pack이름    이항연산자    ...   => (args + ...) 의 형태이므로 nary  right fold 
	//									E1+(E2+(E3+(E4+E5)))
	// printv(1) , ( printv(2), (printv(3), (printv(4) ,  ....... )
	// => fold expresson 은 아주 많은 일을 할수 있습니다

	( std::cout << args ); // 이 코드가 하는일은 ?
}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}



