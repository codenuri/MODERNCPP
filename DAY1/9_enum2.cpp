
// C/C++98 시절의 enum 
// enum COLOR { red = 0, green = 1, blue = 2 };


// C++11 에서 새로나오는 enum 문법 
enum class COLOR { red = 0, green = 1, blue = 2 };


int main()
{
//	int n1 = red;			// error. COLOR 라는 이름 필요
//	int n2 = COLOR::red;	// error. int 타입이 아닌 COLOR 타입
							//        int 타입으로 암시적 변환 안됨
	COLOR c1 = COLOR::red;  // ok
//	COLOR c2 = red;			// error. COLOR 필요

	// 캐스팅하면 int 타입으로 변환 가능합니다.
	int n = static_cast<int>(COLOR::red);
}

// C++98 시절 함수
void foo(int color) {}
foo(red);	// ok. red는 enum 상수
foo(-100);	// 잘못 사용했지만 에러 아님.


// C++11 이후
void foo(COLOR c) {}
foo(COLOR::red); // ok
foo(100); // error. int 는 COLOR 타입 아님.