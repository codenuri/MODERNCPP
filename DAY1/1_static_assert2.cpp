#include <iostream>
#include <type_traits> 

// static_assert : 프로그램의 기능, 성능에 영향을 주지 않고,,
//				   안전성 여부를 컴파일 시간에 조사하는 것..
//				   많이 사용해도 오버헤드는 전혀 없습니다

/*
#pragma pack(1)		// 1byte 단위로 align 해달라.
struct PACKET		// 필요 없는 padding 제외..
{
	char cmd;
	int  data;
};

// #pragma pack 은 C++ 표준은 아닙니다.(단, g++, vc 등은 모두 지원)
static_assert(sizeof(PACKET) == sizeof(char) + sizeof(int),
				"error, unexpected padding");

int main()
{
	std::cout << sizeof(PACKET) << std::endl; // ?
}
*/



template<typename T> void object_set_zero(T* p)
{
	memset(p, 0, sizeof(T)); 
}

class AAA
{
	int data;
public:
};

int main()
{
	AAA aaa;
	object_set_zero(&aaa); // 이 코드를 생각해 봅시다.
}