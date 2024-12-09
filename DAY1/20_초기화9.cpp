// 1_초기화9. - 63 page
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int)      { std::cout << "int" << std::endl;	}
	Point(int, int) { std::cout << "int, int" << std::endl; }
	Point(std::initializer_list<int> e) { std::cout << "initializer_list<int>" << std::endl; }
};

int main()
{
	// 아래 코드가 각각 어떤 생성자를 호출할까요 ?
	Point p1(1);		// Point(int)
	Point p2(1, 2);		// Point(int, int)
	Point p3( { 1,2 } ); // Point(std::initializer_list<int>)


	Point p4{ 1,2 };	// 핵심. 이 코드의 생성자 호출을 정확히 알아야 합니다.
						// 1. Point(std::initializer_list<int>) 가 있다면 사용
						// 2. (1) 이 없다면 Point(int, int) 호출. 

	Point p5(1, 2, 3);	// error. Point(int, int, int) 는 없습니다.

	Point p6{ 1, 2, 3 }; // ok {} 이므로 Point(std::initializer_list<int>) 사용
	
	Point p7 = { 1,2,3 };// ok. Point(std::initializer_list<int>) 는 explicit 아님. 

	// 결론, 생성자 인자로 std::initializer_list<> 를 사용하면 객체를 배열처럼 초기화 
	// 할수 있습니다.
	std::vector<int> v1{ 1,2,3,4,5,6 };		// ok
	std::vector<int> v2 = { 1,2,3,4,5,6 };	// ok
}


