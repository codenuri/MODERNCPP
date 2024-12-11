// QA.cpp
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

// ���α׷����� new �� ����ϸ� "operator new()" ǥ�� �Լ��� ȣ��˴ϴ�.
// ����ڰ� �ٽ� ����� �ֽ��ϴ�
void* operator new(std::size_t sz)
{
	printf("called new : %zd bytes\n", sz);

	return malloc(sz);
}


int main()
{
	std::shared_ptr<Point> sp1(new Point(1, 2));

//	std::shared_ptr<Point> sp2 = std::make_shared<Point>(1, 2);

}







