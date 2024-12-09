#include <iostream>
#include <vector>

struct Point3D
{
	int x, y, z;
	
	// 사용자 정의 타입의 객체를 "range-for" 에 넣으려면
	// begin(), end() 를 멤버 함수 또는 일반함수로 만들면됩니다.
	int* begin() { return &x; }
	int* end() { return &z + 1; } // 마지막 다음 요소..
};

int main()
{
	Point3D p;
	p.x = 10;
	p.y = 20;
	p.z = 30;

	for (int n : p)  // 될까요 ? 되게하려면 필요한 것은 ?
		std::cout << n << std::endl;

}















