#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};
int main()
{
	// 스마트 포인터
	// 1. 직접 객체 생성
	// 아래 코드는 동적 메모리를 몇번 할당 할까요 ? 2번
	// 1. 사용자가 만든 코드 "new Point"
	// 2. shared_ptr 생성자에서 control block 생성

	std::shared_ptr<Point> sp1( new Point(1,2) );


	// 스마트 포인터 코딩 관례
	// => 객체를 직접 new 로 생성하지 말고
	// => std::make_shared() 를 사용해라

	std::shared_ptr<Point> sp2 = std::make_shared<Point>(1, 2);
			// 1. sizeof(Point) + sizeof(control block) 을 한번에 할당
			// 2. 객체(Point) 부분에 대해서 생성자 호출(인자로 전달된 1,2) 사용

	// 즉, make_shared 가 받은 2개의 인자 1, 2 를
	// => Point 생성자에 전달(forwarding) 하는것
	// => 완벽한 전달 기술로 구현되어 있다.
}







