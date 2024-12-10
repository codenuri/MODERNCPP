// move 개념을 이해 하려면 "복사 생성자"를 정확히 알고 있어야 합니다.
// 
// 복사생성자 모양을 생각해 봅시다.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 복사 생성자를 직접 만들어 봅시다.
	// 
	// 방법 #1. call by value
	// => 인자를 전달 받는 모양이 "Point other = p2" 인데..
	//    이 모양이 다시 복사 생성자를 호출하는 모양입니다.
	// => 이 모양은 "복사생성자를 무한히 호출" 하는 코드 입니다.
	// => 컴파일 에러. 
	// Point(Point other) {}


	// 방법 #2. call by non-const reference
	// => 인자를 받을때 "Point& other = p2" 이므로 복사본 생성 안됨.
	// => 컴파일 가능. 
	// => 단점 : rvalue(임시객체) 를 받을수 없다.
	// =>        "Point p5 = foo()" 코드가 에러(C++14까지)
	//			 단, C++17 부터는 에러가 발생하지 않습니다.(Copy Ellision 문법때문)
//	Point(Point& other) {}

	// 결론 : 복사 생성자는 아래 2가지 경우 모두 사용가능해야 합니다.
	// Point ret1 = p1;
	// Point ret2 = foo();

	// 그래서, 복사 생성자의 인자는 "const Point&" 가 되어야 합니다.
	Point(const Point& other) : x{ other.x }, y{ other.y } {}
};

Point foo()
{
	Point pt{ 1,2 };
	return pt;
}

int main()
{
	Point p1;			// 1번 생성자 사용
	Point p2(1, 2);		// 2번 생성자 사용

	Point p3(p2);		// 컴파일러가 만들어주는 "복사 생성자" 사용	(직접 초기화)			
	Point p4 = p2;		// 이 모양도 복사 생성자 호출(복사 초기화)

//	Point p5 = foo();   // Point p5(foo()); 이므로
						// point p5(임시객체);
}




