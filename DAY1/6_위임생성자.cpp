#include <iostream>

// 6_위임생성자 - 24page
class Point
{
public:
	int x, y;
public:
	// C++98/03 : 생성자에서 다른 생성자 호출 안됨
	// C++11 ~  : 생성자에서 다른 생성자 호출 가능. 단, 아래 표기법으로해야 합니다.

	Point() : Point (0, 0)   // 위임 생성자라고 합니다.
	{
//		Point(0, 0); // ? 생성자 안에서 다른 생성자 호출 ?
					 // => 안됩니다. 
					 // => 이 코드는 생성자에서 다른 생성자를 호출하는 코드가 아닙니다.
					 // => 이 코드는 "임시객체"를 생성하는 코드 입니다.
	}

	Point(int a, int b) : x(a), y(b)
	{
		// 복잡한 초기화 코드
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

