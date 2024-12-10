// 2_타입추론5-1.cpp

int main()
{
	// auto 와 배열
	int x[3] = { 1,2,3 };

	// 아래 a1, a2 의 타입을 예측해 보세요
	auto  a1 = x;	// 1. int a1[3] = x;   라고 했다면 컴파일 에러. 
					// 2. int* a1 = x;	   라고 했다면 에러 아님.
					// => 컴파일러는 2번으로 결정
					// => auto 의 우변이 배열인경우, auto 는 포인터로 결정됨

	auto& a2 = x;	// int(&a2)[3] = x; 로 해도 에러가 아니다.
					// 따라서, 이 경우는
					// auto : int[3]   a2 : int(&)[3]

	// 결론, auto 를 배열로 초기화 할때
	// 값 타입(auto)   : auto 는 포인터로 결정
	// 참조타입(auto&) : auto 는 배열로 결정

	auto  a3 = x; // auto : int*
	auto& a4 = x; // auto : int[3],   a4 : int(&)[3]
}