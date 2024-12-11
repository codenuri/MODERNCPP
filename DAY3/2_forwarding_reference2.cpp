// reference collapsing - 91 page
// => T&& 를 이해 하기 위한 사전 지식

int main()
{
	int n = 10;


	int *p = &n;
	int* *pp = &p;	// ok. 포인터의 포인터(이중 포인터)는 만들수 있습니다.

	int& r = n;
	int& &rr = r;	// error. reference 의 reference(이중 reference) 를 직접 코드로 만들수 
					//        없습니다.


	// 하지만, alias 또는 템플릿 등을 사용시 발생하는 "reference 의 reference" 는 에러가 
	// 아니고, "reference collapsing" 규칙으로 타입을 결정한다.
	using LREF = int&; 
	using RREF = int&&;

	// reference collapsing
	// => T&& 개념을 만들기 위해 만들어진 규칙
	// => 반드시 외워 두세요
	LREF& r3 = n;		// int&   &		=> int&
	RREF& r4 = n;		// int&&  &		=> int&
	LREF&& r5 = n;		// int&   &&	=> int&
	RREF&& r6 = 3;		// int&&  &&	=> int&&
}

template<typename T> void foo(T a)
{
	T& r = a; // 아래 코드처럼 호출시 r의 타입을 생각해 봅시다.
			  // int& & => int&
			  // int& r = a;
}

int n = 0;
foo<int&>(n); 





