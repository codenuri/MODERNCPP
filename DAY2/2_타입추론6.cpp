// decltype 타입 추론 - 71page
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	// auto vs decltype
	auto a = n;		// 우변의 초기값으로 타입을 결정
					// int a = n;
	decltype(n) d;	// () 안에 있는 표현식의 타입을 조사해서 결정
					// int d;


	// decltype(expression)
	// 규칙 #1. expression 이 심볼의 이름일때
	decltype(n) d1; // 
	decltype(r) d2; // 
	decltype(c) d3; // 
	decltype(p) d4; // 
}
