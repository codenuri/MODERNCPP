#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}

void f0() {}
int& f3(int a, double d, int& r) { r = 100; return r; }

// 완벽한 전달의 코딩 관례
// 1. 인자 갯수에 제한을 없애기 위해서 "가변인자 템플릿(5일차배우는내용)" 사용
// 2. 반환 값도 완벽히 돌려주어야 합니다. - decltype(auto) 로 반환

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	// StopWatch sw;  // 생성자에서 시간 기록
					  // 소멸자에서 수행시간 화면 출력
	return f(std::forward<T>(arg)... );
}

int main()
{
	int n = 0;
	
	chronometry(f0); // f0()
	
	int& ret = chronometry(f3, 1, 3.4, n); // f3(1, 3.4, n)

	ret = 300; // n = 300
	std::cout << n << std::endl; // 300
}
