#include <complex>

int main()
{
	// C++98 스타일 초기화
	// => 변수의 종류에 따라 초기화 방법이 다르다.
	int n1 = 10;
	int x1[2] = { 1,2 };
	std::complex<double> c1(1, 2);

	// C++11 스타일 초기화
	// => "uniform initialization(일관된 초기화)" 라고 불리는 문법
	// => 흔히 중괄호 초기화(brace init) 이라고도 부릅니다.
	// => 모든 종류의 변수를 {} 로 초기할수 있다는 의미. 
	int n2 = { 10 };
	int x2[2] = { 1,2 };
	std::complex<double> c2 = { 1, 2 };

	// = 이 없어도 됩니다.
	int n3{ 10 };
	int x3[2]{ 1,2 };
	std::complex<double> c3{ 1, 2 };

	// copy(복사)   initialization : = 이 있는 경우
	// direct(직접) initialization : = 이 없는 경우.
	// => 위 2개는 약간의 차이점이 있습니다.
	// => explicit 배울때 설명
}












