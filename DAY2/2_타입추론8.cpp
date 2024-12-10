int main()
{
	int x[3] = { 1,2,3 };

	// auto 와 decltype 의 차이점

	auto a = x[0];		// int a = x[0];

	decltype(x[0]) d;	// int& d;		// 초기값 없다고 error.

	// 배열의 경우
	auto  a1 = x;		// int* a1 = x;
	auto& a2 = x;		// int(&a2)[3] = x;

	decltype(x) d1;		// int d1[3];
						// 심볼의 이름만 있으므로 규칙 #1 적용
}

