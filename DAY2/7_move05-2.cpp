// 7_move05-2.cpp   �ӽð�ü 1������ �Ʒ� �ڵ� ����
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
	// �Ʒ� ���ٿ� ���ؼ� �Ϻ��� ������ ���ô�. 
	Point pt = Point(1, 1);


}