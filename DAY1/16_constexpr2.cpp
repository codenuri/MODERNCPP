// C++11 에서 추가된 constexpr

// constexpr : 컴파일 시간 상수 만들때 사용
// 기존 const : readonly 의 의미!!

int main()
{
	int n = 3;
	const int c1 = 3;
	const int c2 = n;

	constexpr int c3 = 3;
	constexpr int c4 = n;
}