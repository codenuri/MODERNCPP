// 12_delete_function 37 page

class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}

	// 클래스 만들때 사용자가 만들지 않아도 컴파일러가
	// => 복사 생성자, 대입연산자등을 자동으로 제공합니다.

	// 함수 삭제 문법 : 컴파일러에게 특정 함수를 만들지 말라고 지시하는 것
	Point(const Point&) = delete;	// 디폴트 복사 생성자를 만들지 말라(삭제해라)

	Point operator=(const Point&) = delete;
};
int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2); // 컴파일러가 만들어주는 복사생성자사용
}
