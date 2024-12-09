// 9_enum - 32 page

// C/C++98 시절의 enum 
enum COLOR { red = 0, green = 1, blue = 2};

int main()
{
	int n1 = COLOR::red; // 정확한 표기법
	int n2 = red;		 // ok. COLOR 라는 이름 생략 가능 

	int red = 10; // ok. enum 상수와 동일한 이름의 변수 생성 가능

	int n3 = red; // 여기서 red 는 지역변수!

	// enum 상수 사용시 이름(COLOR) 를 
	// 생략할수 있는 것이 좋은 문법 일까요 ?
}





