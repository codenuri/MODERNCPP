// 2_typename

struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p1 = 0;

template<typename T> void foo(T a)
{
	// 아래 코드에서 * 의 의미를 생각해 보세요
//	Test::data  * p1;	// 곱하기 의미
//	Test::DWORD * p2;	// 곱하기 의미가 아니고, 포인터 변수의 선언

	// "클래스이름::이름" 에서 "이름" 의 의미는
	// 1. 값		: static 멤버데이타, enum 상수등.
	// 2. 타입  : typedef, using 등
	// 일수 있습니다.
	// "이름"의 의미에 따라 * 등의 연산자의 의미가 달라집니다.

	//-------------------------------------------
	
	T::data * p1;
	T::DWORD* p2;
}

int main()
{

}



