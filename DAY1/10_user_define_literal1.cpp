#include <iostream>

class Meter
{
	int value;
public:
	Meter(int v) : value(v) {}
};

// 아래 함수를 "사용자 정의 리터럴 접미사" 를 만드는 코드 입니다.
Meter operator""m(int n)
{
	Meter met(n);
	return met;
}


int main()
{
	Meter met = 3m; // operator""m(3) 을 호출하기로 약속되어 있습니다.


//	float f = 3.4;  // 3.4 만 표시하면 double 타입
//	float f = 3.4f; // 이렇게 하면 float 타입의 3.4
}




