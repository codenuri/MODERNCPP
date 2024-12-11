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
			//    "완벽한 전달 기술이 있기 때문에 가능한 함수 입니다"



	std::cout << "-----" << std::endl;
}

// main						emplace_back				Point(int a, int b)
// emplace_back(1, n); =====> 1,n 를 받아서
//							new Point(1,n)
//							 다시 생성자에 전달 ===============> ok.. 변화없이 받아야한다.

// 참고 : vector 등의 컨테이너에 요소를 삽입할때

// #1. primitive 타입을 저장하는 vector 
// => 복사생성자 등의 개념없으므로 그냥 push_back 으로 넣으세요
std::vector<int> v;
v.push_back(n);


// #2. pointer 타입을 저장하는 vector
// => pointer 는 복사생성자 등의 개념없으므로 그냥 push_back 으로 넣으세요
std::vector< Point* > v;
v.push_back(new Point(1,1) );

// #3. 사용자 정의 타입을 "값" 으로 보관할때
// => 넣기만 한다면 push_xxx 보다는 emplace_xxx 로하세요
std::list< Point > c;
c.push_back(Point{ 1,2 })			=> c.emplace_back(1, 2)
c.push_front(Point{ 1,2 })			=> c.emplace_front(1, 2)
c.insert(위치반복자, Point{ 1,2 })	=> c.emplace(위치반복자, 1, 2)