// 함수 인자와 레퍼런스

void f1(int&  r) {}
void f2(int&& r) {}

int main()
{
	int n = 3;

	// 아래 4줄을 생각해 봅시다.
	f1(n); // ok
	f1(3); // error
	f2(n); // error
	f2(3); // ok
}

// 함수 인자로
// int&  : 정수형 lvalue 만 받겠다는 의도
// int&& : 정수형 rvalue 만 받겠다는 의도
// 
// T&    : 


template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 3;

	// #1. 타입인자를 직접 전달하는 경우 생성된 함수를 생각해 봅시다.
	f3<int>(n );	// T= int		T&=	int&				f3(int& a)
	f3<int&>(n );	// T= int&		T&=	int& &  => int&		f3(int& a)
	f3<int&&>(n );  // T= int&&		T&=	int&& & => int&		f3(int& a)
		
	// 결국 T = int, int&, int&& 의 모든 경우에 생성되는 함수는
	// 동일합니다. f3(int& a)

	// #2. 타입 인자를 직접 전달하지 않은 경우
	// => 컴파일러가 함수인자를 보고, T를 결정해서 함수를 생성
	f3(3);
	f3(n);
	
}






template<typename T> void f4(T&& a)
{
}
