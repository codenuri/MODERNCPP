#include <iostream>

class Point
{
	int x = 0;  // C++11 부터 멤버데이타(필드)를 직접 초기화 가능 
	int y = 0;
public:
	Point() {}
	Point(int y)        : y(y) {}
	Point(int x, int y) : x(x), y(y) {}
};

// 위 코드의 정확한 원리
// => 위 클래스를 컴파일러가 아래 처럼 변경하게 됩니다.
class Point
{
	int x;   // = 0;
	int y;   // = 0;
public:
	// 위 초기값 때문에 생성자가 아래 처럼 변경 됩니다.
	Point()      : x(0), y(0) {}
	Point(int y) : x(0), y(y) {}
	Point(int x, int y) : x(x), y(y) {}
};



int main()
{
	Point pt(1, 1);
}
