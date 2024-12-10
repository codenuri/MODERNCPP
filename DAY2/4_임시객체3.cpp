#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자 - 81 page
void draw_line(const Point& from, const Point& to) {}

void init(Point& pt) { pt.x = 0; pt.y = 0; }

int main()
{
	// (0, 0) ~ (9, 9) 사이에 선을 그리고 싶다

	// 방법 #1. 객체를 생성한후 인자로 전달
	Point p1{ 0, 0 };
	Point p2{ 9, 9 };

	draw_line(p1, p2); 


	// 방법 #2. 임시객체 형태로 전달
	// => 함수 인자로만 사용하고
	// => 함수 호출이 종료된후 즉시 파괴 됩니다.
	// => 방법 #1 보다 이 방법이 좋습니다.
	draw_line(Point{0, 0}, Point{9, 9});



	// 임시객체와 참조!!
	Point p1{ 1,1 };

	init(p1);		// ok


	init( Point{ 1,1 } );	// error
							// 임시객체를 non-const reference 로는 받을수 없다.
							// non-const reference 의 의미는 값을 수정하겠다는것
							// 함수 호출뒤 파괴될 객체의 값을 수정하는 것은
							// 논리적으로 맞지 않다.


	std::cout << "-----" << std::endl;
}





