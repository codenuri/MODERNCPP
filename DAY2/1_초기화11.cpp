// 1_초기화11 - 65 page..
// aggregate initialization

// aggregate type
// => 여러개의 요소를 가지는 타입으로
// => 생성자 없이도 {}로 초기화 가능한 타입
// => C언어, 구조체, 배열등.. 

struct Point
{
	int x, y;

//	Point()             : x(0), y(0) {}	// 1
//	Point(int a, int b) : x(a), y(b) {}	// 2

//	Point() {} // 사용자가 만든 디폴트 생성자가 있으면
			   // aggregate 아닙니다. C 구조체 초기화 문법 사용못함.

//	Point() = default; // 컴파일러가 만든 생성자가 있다면
						// C++17 까지 - aggregate 타입. 
						// C++20 이후 - aggregate 아님..

//	virtual void foo() {} // 가상함수가 있다면 aggregate 아님

	void goo() {} // 가상이 아닌 멤버함수는 있어도 aggregate 
};

int main()
{
	Point p1;	
	Point p2 = { 1, 2 };
}
