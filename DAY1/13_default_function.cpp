// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// 인자가 없는 생성자가 필요할때
	// 생성자를 만드는 2가지 방법
	// #1. 사용자가 직접 구현부를 제공
	// Point() {} 



	// #2. 컴파일러에게 만들어 달라고 요청
	// => 특징 : 컴파일러가 생성자를 구현하게 되므로 "어떻게 구현했는지" 를 정확히 알고 있습니다.
	//           따라서 다양한 최적화를 지원 받을수 있습니다.
	//           앞으로 계속 나오는 문법 입니다.
	Point() = default;


	// 핵심 : 아무 일도 하지 않은 기본 생성자가 필요 하면
	//       실제 구현부를 제공(#1번) 하는 것 보다 "= default" 로 요청(#2번) 하는것이
	//       좋은 코드 입니다.
};

int main()
{
	Point p1;
	Point p2(1, 2);
}

// 웹브라우져 실행하고, "godbolt.org" 사이트 접속해 보세요


