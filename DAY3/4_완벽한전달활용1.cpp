// 8_완벽한전달활용
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};

int main()
{
	std::vector<Point> v;
	
	// vector에 요소 넣기. 
	// 
	// 1. 객체를 생성해서 push_back 으로전달. 
//	Point pt(1, 2);
//	v.push_back(pt);

	// 2. 임시객체 형태로 push_back에 전달
	// => 위 와의 차이점은 임시객체이므로
	//    소멸자 호출이 ----- 보다 빠르다는 점.
//	v.push_back( Point{ 1,1 } );


	// 3. 핵심
	// => 객체를 전달하지 말고 객체를 만들기 위한
	//    생성자 인자값을 전달하자.

	v.emplace_back(1, 2);
			// => emplace_back 이 내부적으로 자신의 버퍼에 Point 생성
			//    new Point(1, 2) 형태로 생성
			//    



	std::cout << "-----" << std::endl;
}


