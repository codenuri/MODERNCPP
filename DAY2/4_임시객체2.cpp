// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체의 특징 - 79 page
int main()
{
	Point pt{ 1, 2 };
	
	// 특징 #1. 임시객체는 등호의 왼쪽에 올수 없다.(lvalue 가 될수 없다. rvalue)
	pt.x = 10;				// ok
	Point{ 1, 2 }.x = 10;	// error.
						

	// 특징 #2. 임시객체는 주소 연산자(&)로 주소를 구할수 없습니다.
	// => 단, 생성자 안에서 this 등으로 주소를 확인할수 있습니다.
	Point* p1 = &pt;			// ok
	Point* p2 = &Point{ 1, 2 };	// error.
							

	// 특징 #3. 임시객체는 non-const (lvalue) reference 로는 가리킬수 없다.
	Point& r1 = pt;				// ok
	Point& r2 = Point{ 1, 2 };	// error


	// 특징 #4. 임시객체를 const (lvalue) reference 로는 가리킬수 있다.
	const Point& cr = Point{ 1, 2 };	// ok
								// 이 경우, 임시객체의 수명이 "cr" 의 수명으로 연장됩니다.
								// cr 이 파괴 될때 임시객체 파괴
								// life time extension 이라고 합니다.(RUST 같은 언어에도 존재)
								// 왜이런 문법을 만들었나요 ? - 임시객체3.cpp 참고!!

	// 특징 #5. C++11 부터는 상수성 없이 임시객체를 가리킬 필요가 생겼습니다.
	// (move, perfect forwarding 기술을 위해)
	// => rvalue reference 라는 문법 도입. 
	// => 임시객체(rvalue) 만 가리키는 reference 
	// => const 추가하지 않고도 가리킬수 있다.
	Point&& rr = Point{ 1,1 }; // life time extension 발생 

}





