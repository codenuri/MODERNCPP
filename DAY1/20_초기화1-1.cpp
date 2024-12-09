#include <iostream>

int x = 10;

class Test
{
	int value1 = 0;   // ok. 좋은 코드
	int value2 = ++x; // 에러는 아니지만 절대 이렇게 하지 마세요
					  // 혼란스럽게 됩니다.!!!!!
					  // 이 위치는 = 0 같은 초기화만 사용하세요. 
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
