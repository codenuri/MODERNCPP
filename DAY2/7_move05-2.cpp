// 7_move05-2.cpp   임시객체 1번에서 아래 코드 복사
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	// 아래 한줄에 대해서 완벽히 이해해 봅시다. 
	Point pt = Point(1, 1);


}