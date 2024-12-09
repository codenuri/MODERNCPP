#include <cassert>

// 7 page

// 
// static_assert(C++11) : 컴파일시간 표현식의 유효성을 조사, 
//				   false 인 경우, 컴파일을 중지하고, 메세지 출력

// #1. 함수 안/밖 모두 가능
// #2. 표현식은 반드시 컴파일 시간에 조사 가능해야 한다
//     변수는 안됨. 

int main()
{
	static_assert(sizeof(void*) == 8, "error, this code can use only 64 bit!");

//	int n = 10;
//	static_assert(n == 10, "aa"); // n 은 변수라서 사용 안됨.   
}
