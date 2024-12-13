#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types> void foo(Types ... args)
{
	// arg라는 pack 에 있는 모든 요소(1,2,3) 를 printv()에 보내서 화면 출력하고 싶다

//	printv(args...);	// error. printv(e1, e2, e3) 인데, printv()인자는 한개.

//	printv(args)...;	// error.
						// printv(e1), printv(e2), printv(e3); 의 의도지만
						// pack expansion 은 모든 곳에서 할수 있는것은 아닙니다.

	// pack expansion 은 아래의 위치에서만 가능합니다.
	// 1. 함수 호출 () 안에서 인자로 ..    goo(args...) => goo(e1, e2, e2)
	// 2. {} 초기화 구문에서				 int x[] = { args...}; => {e1, e2, e3}
	// 3. 템플릿 인자				std::tuple<Types...> => std::tuple<int, int,int>

	// 따라서, 위 의도 대로 하려면 아래 처럼해야 합니다.
	int dummy[] = { printv(args)... };  // { printv(e1), printv(e2), printv(e3) }
}


int main()
{
	foo(1, 2, 3);
}

