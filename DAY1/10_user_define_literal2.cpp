#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::literals; // C++ 표준이 제공하는 다양한 literal 접미사를 사용하기 위해

void foo(const char* s) { std::cout << "char*"; }	// 1
void foo(std::string s) { std::cout << "string"; }	// 2

int main()
{
	foo("hello");	// 1. 정확히는 const char[6] 인데, const char* 로 변환 가능
	foo("hello"s);  // 2. std::string operator""s(const char*) 가 호출된것
		
//	std::this_thread::sleep_for( 3 ); // 현재 스레드를 특정 시간동안 재우기
									  // 인자로는 반드시 초, 분, 시간등의 타입만 가능.

	std::chrono::seconds sec(3); // 3초 객체
	std::this_thread::sleep_for(sec); // ok 

	std::this_thread::sleep_for( 3s );	// ok
										// operator""s(unsinged long long) 이 호출된것

	// s, ns, ms, us, min, h 모두 있습니다.
	std::this_thread::sleep_for(3ms);

	std::vector<std::string> v1 = { "AA", "BB" }; 

	std::vector v2 = { "AA", "BB" };	// C++17 부터는 클래스 템플릿 사용시 타입 생략가능
										// 그런데, 이코드는 요소의 타입이 const char*

	std::vector v3 = { "AA"s, "BB"s };  // ok. 요소의 타입이 std::string
}


