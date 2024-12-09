#include <iostream>

int x = 10;

class Test
{
	int value1 = 0;
	int value2 = ++x;
public:
	// 사용자 코드					// 컴파일러가 변경한 코드
	Test() {}						// Test()      : value1(0), value2(++x) {} <= 1
	Test(int n) : value2(n) {}		// Test(int n) : value1(0), value2(n) {}   <= 2
};

int main()
{
	Test t1;	// 1번 생성자 호출, ++x 실행
	Test t2(5);	// 2번 생성자 호출, ++x 실행 안됨. 

	std::cout << x << std::endl; // 결과.. 예측해보세요. ?
								// 11 
}
