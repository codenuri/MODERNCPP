// 20_타입추론5

template<typename T> void foo(T a) {}

int main()
{
	// 템플릿은 호출시 전달한 인자로 타입 추론
	foo(10);
//	T    a = 10; // 결국 이 형태가 됩니다. 아래 auto 와 같은 모양이 됩니다.
	auto a = 10; // 그래서, template 과 auto 가 동일 규칙 입니다.


	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto 추론은 템플릿 추론과 동일합니다.
	// 아래 각 변수의 타입을 생각해 보세요
	// T a1 = n; 의 형태가 되므로, "규칙 #1. 템플릿 인자가 값 타입일때" 를 적용해야 합니다.
	//							  인자(우변)이 가진 const, volatile, reference 제거후
	//							  타입 결정
	auto a1 = n;  // a1 : int
	auto a2 = r;  // a2 : int
	auto a3 = c;  // a3 : int 
	auto a4 = cr; // a4 : int


	// 아래 코드는 auto& 이므로 foo(T&) 인 경우 입니다.
	// 규칙 #2. 인자가 & 일때, 인자(우변)가 가진 reference 속성만 제거하고 T(auto) 결정
	//		    const, volatile 은 유지. 
	// T& a5 = n;

	auto& a5 = n;	// auto = int			a5 = int&
	auto& a6 = r;	// auto = int			a6 = int&
	auto& a7 = c;	// auto = const int		a7 = const int&
	auto& a8 = cr;  // auto = const int		a8 = const int&

	// 위 내용을 직접 확인해 보기는 쉽지 않습니다.
	// => 그래서, template 으로 학습한후..
	// => 동일 규칙으로 auto 를 생각하면 좋습니다.
}


