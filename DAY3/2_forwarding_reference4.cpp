template<typename T> void f4(T&& a)
{
}

int main()
{
	int n = 3;

	// #1. 타입을 직접 전달하는 경우
	f4<int>(3 );	// T = int		T&& = int&&					f4(int&& a)
	f4<int&>(n );	// T = int&		T&& = int&  && => int&		f4(int& a)
	f4<int&&>(3 );	// T = int&&	T&& = int&& && => int&&		f4(int&& a)


	// #2. 타입을 전달하지 않은 경우
	// => 함수 인자를 보고 T 의 타입을 결정해서 함수를 생성
	f4(n);	// n 은 int 타입이므로 T = int 로 결정하면, f4(int&& a) 생성
			// => 그런데, f4(int&&) 는 lvalue 를 받을수 없으므로 error.
			// 
			// 그런데, T = int& 로 결정했다면 f4(int& a) 함수가 생성되므로
			// => f4(n) 이 에러가 아니다.

	f4(3);	// 3은 int, T=int 로 결정, f4(int&&) 함수 생성
			// => ok.. 문제 없음. 
}

// 참고, 템플릿과 타입 추론
template<typename T> void foo1(T a) {}
template<typename T> void foo2(T& a) {}
template<typename T> void foo3(T&& a) {}
int n = 3;
foo1(n);	// T = int
foo2(n);	// T = int
foo3(n);	// T = int&   <== 핵심  시험에 나옵니다. 꼭 외워 두세요