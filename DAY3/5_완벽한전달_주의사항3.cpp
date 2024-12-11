// 9_완벽한전달_주의사항3

// forwarding reference 이야기

template<typename T> class Test
{
public:
	// 아래 함수는 forwarding reference 가 아닙니다.
	// 아래 함수는 "함수 템플릿" 이 아닙니다.
	// 아래 함수는 "클래스 템플릿의 일반 멤버 함수"아닙니다.
	// => T의 타입이 함수 호출시 결정되는 것이 아니라
	//    객체를 생성할때 T의 타입이 결정됩니다.
	void foo(T&& arg)
	{
	}

	// forwarding reference 가 되려면 "함수 자체가 template" 이어야 합니다.
	// => U 의 타입이 함수 호출 코드를 통해서 결정됩니다.
	template<typename U> void goo(U&& arg) {}
};
int main()
{
	int n = 0;
	Test<int> t;	// T = int 로 결정
					// foo(int&&) 로 결정됨.
	
	// 아래 코드를 생각해보세요. 에러가 있을까요 ?
	t.foo(n);		// error
	t.foo(10);		// ok

	t.goo(n);		// ok
	t.goo(10);		// ok
}
