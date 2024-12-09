#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point()				: x{ 0 }, y{ 0 } {}
	Point(int a, int b) : x{ a }, y{ b } {}
//	explicit Point(int a, int b) : x{ a }, y{ b } {}
};

void foo(Point pt)
{
}

int main()
{
	// C++11 이후 {} 초기화 가능. 
	Point p1{ 1,2 };
	Point p2 = { 1,2 }; // explicit 라면 에러

	foo(p1);

	// {} 초기화 때문에 아래 처럼 사용하는 것도 가능합니다.
	foo({1, 2}); // Point pt = {1,2}
				// explicit 라면 에러
}

Point goo() 
{ 
	// 아래 표기법도 가능합니다.
	return { 1, 2}; // Point{1,2}
					// explicit 라면 에러
} 