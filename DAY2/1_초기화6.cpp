// 1_초기화6 - 60 page
#include <iostream>

struct Point
{
	int x;
	int y;

//	Point() {}	// 사용자가 만든 생성자

	Point() = default; // 컴파일러에게 요청
};

int main()
{
	int n1{ 0 };	// 직접(direct) 초기화
	int n2 = { 0 };	// 복사(copy) 초기화	
	int n3;			// 디폴트(default) 초기화, 
					// int 타입은 쓰레기값
					// user define type : 디폴트 생성자 호출

	int n4{};		// value initialization	
					// 값이 없는 빈 {}
					// int 같은 primitive 타입 : 0으로 초기화
					// => int 타입은 {} 보다는 {0} 권장

	std::cout << n4 << std::endl; // 0

	Point pt{};	// 1. 사용자가 생성자를 직접 만든 경우
				// => 사용자가 생성자만 호출!!
				// 
				// 2. 생성자가 없거나, "=default" 로 만든경우
				// => 모든 멤버가 0으로 초기화

	std::cout << pt.x << std::endl;

	// 참고 : 아래 코드는 객체 생성이 아닌, 함수 선언 입니다
//	Point pt();
}

