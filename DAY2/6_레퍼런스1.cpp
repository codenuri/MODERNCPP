// 3_레퍼런스1.cpp - 89 page - 아주 중요!

struct Point
{
	int x, y;

	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point pt(0, 0);

	// 아래 규칙은 반드시 외우고 있어야 합니다.


	// 규칙 #1. non-const lvalue reference 로는 lvalue 만 가리킬수 있다.

	Point& r1 = pt;				// ok
	Point& r2 = Point{ 0, 0 };	// error


	// 규칙 #2. const lvalue reference 로는 lvalue, rvalue 를 모두 가리킬수 있다.

	const Point& r3 = pt;				// ok
	const Point& r4 = Point{ 0, 0 };	// ok


	// 규칙 #3. rvalue reference 로는 rvalue 만 가리킬수 있다.
	// => C++11 만들때 추가한 개념
	// => rvalue 를 상수성을 추가하지 않고 가리키고 싶었다(move, 완벽한 전달)
	// => rvalue reference 라는 새로운 문법이 추가됨
	Point&& r3 = pt;			// error.
	Point&& r4 = Point{ 0, 0 };	// ok

	// const 가 붙어도 rvalue 만 가리킬수 있습니다.
	// => 그런데, const rvalue reference 를 사용할일은 없습니다.(이유는 move 배운후)
	const Point&& r5 = pt;			// error.
	const Point&& r6 = Point{ 0, 0 };	// ok

}
