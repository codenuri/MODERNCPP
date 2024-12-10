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
	// 방법 #1. call by value
	Point(Point other) {}
};

int main()
{
	Point p1;			// 1번 생성자 사용
	Point p2(1, 2);		// 2번 생성자 사용
	Point p3(p2);		// 컴파일러가 만들어주는 "복사 생성자" 사용				
}




