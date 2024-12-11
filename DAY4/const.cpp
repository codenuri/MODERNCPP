// const.cpp - day4 에 있는 소스 복사해 오세요

// 상수 멤버 함수 라는 문법 설명 - C++ 기본 과정에서 배우는 내용
class Point
{
	int x = 0;
	int y = 0;
public:
	// 일반적인 멤버 함수에서는
	// 멤버 데이타를 Read/Write 하게 됩니다.
	void set(int a, int b)
	{
		x = a;
		y = b;
	}
	// 상수 멤버 함수
	// => 1. 멤버 함수 안에서 멤버 데이타를 수정하지 않겠다는 약속
	//       (멤버 데이타를 수정하는 코드가 있다면 error)
	// => 2. 상수 객체는 상수 멤버 함수만 호출할수 있다.
	int getx()   const 
	{
//		x = 0; // error
		return x;
	}
};

//void foo(Point pt) // call by value, 복사본 오버헤드 있음. 나쁜 코드
void foo(const Point& pt) // 권장..
{
	int x = pt.getx(); 
}

int main()
{
//	Point pt;	// 상수가 아닌 객체
	const Point pt;	// 상수 객체.. 

	pt.set(1, 2);	// error. 상수 객체는 멤버 함수를 호출 할수 없다.

	int n = pt.getx();	// error. const 멤버 함수가 아니라면
						// ok.    const 멤버 함수 라면
}

// #1. 상수 객체는 상수 멤버 함수만 호출할수 있습니다.
// #2. 멤버 함수중 멤버 값을 변경하지 않은 함수 ( getter ) 는 반드시
//     상수 멤버 함수로 해야 합니다.
//     위 getx() 는 반드시 const 가 붙어야 합니다.

// #3. 상수 객체는 생각 보다 아주 많이 사용됩니다. - 함수 인자로 const &
//     void foo(const Point& pt) // <= pt는 상수 객체
//     {
//			int x = pt.getx(); // <= 호출할수 있어야 합니다.
//	   }