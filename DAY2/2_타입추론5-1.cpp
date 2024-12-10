// 2_타입추론5-1.cpp

int main()
{
	// auto 와 배열
	int x[3] = { 1,2,3 };

	// 아래 a1, a2 의 타입을 예측해 보세요
	auto  a1 = x;
	auto& a2 = x;
}