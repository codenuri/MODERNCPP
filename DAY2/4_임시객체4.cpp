// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// 임시객체와 함수 반환값 -  82 page
/*
void f1(Point  pt) {}	// call by value     : 인자의 복사본 생성
void f2(Point& pt) {}	// call by reference : 복사본 생성안됨


int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/




//--------------------

Point pt(1, 2);


Point foo() // return by value
{			// => 리턴용 복사본객체(임시객체)가 생성되어서 반환

	return pt;	// 1. pt 를 복사한 임시객체가 생성되고
				// 2. 임시객체를 반환 한것
}

Point& goo()	// return by reference
{				// => 임시객체가 아닌 pt 의 별명을 반환
	return pt;
}

int main()
{
	foo().x = 10;	// error.	임시객체.x = 10 의 의미
	goo().x = 10;	// ok		"pt.x = 10" 의 의미
}




