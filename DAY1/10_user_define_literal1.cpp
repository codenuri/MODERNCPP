#include <iostream>

class Meter
{
	int value;
public:
	Meter(int v) : value(v) {}
};

// 아래 함수를 "사용자 정의 리터럴 접미사" 를 만드는 코드 입니다.
// => 함수 인자 타입이 약속되어 있습니다. ( 34 page 아래 표)
// => 정수형 리터럴 접미사는 "unsigned long long" 으로 해야 합니다.

// 또한
// _ 로 시작되지 않은 이름은 "표준에서만 사용하기로 약속" 되어 있고
// 개발자가 직접 만드는 것은 반드시 _로 시작해야 합니다.
// => 그런데, 만들지는 말고, 표준것만 사용하세요.. 
Meter operator""_m(unsigned long long n)
{
	Meter met( static_cast<int>(n) );
	return met;
}


int main()
{
	Meter met = 3_m; // operator""m(3) 을 호출하기로 약속되어 있습니다.


//	float f = 3.4;  // 3.4 만 표시하면 double 타입
//	float f = 3.4f; // 이렇게 하면 float 타입의 3.4
}




