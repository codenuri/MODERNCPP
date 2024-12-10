// 4_rvalue - 87 page
int x = 0;

int  foo() { return x; } // x 가 아닌 x의 값 0 반환
int& goo() { return x; } // 0 이 아닌 x 자체를 반환


// lvalue : 등호의 왼쪽에 올수 있는 표현식(왼쪽, 오른쪽 모두 가능)
//			이름을 가진다. 단일 식을 넘어서도 사용가능. 
//			주소연산자로 주소를 구할수 있다.
//			reference type 으로 반환하는 함수
//			문자열 literal
// 
// rvalue : 등호의 왼쪽에 올수 없는 표현식
//			이름이 없고, 단일 식에서만 사용가능.
//			주소연산자로 주소를 구할수 없다.
//			값 타입으로 반환하는 함수
//			정수, 실수형 literal
//			임시객체 



int main()
{
	int v1 = 10, v2 = 10;

	v1 = 20;	// ok.    v1 은 등호의 왼쪽에 올수 있다. lvalue
	10 = v1;	// error. 10 은 등호의 왼쪽에 올수 없다. rvalue
	v2 = v1;

	int* p1 = &v1;	// ok
	int* p2 = &10;	// error.

	foo() = 10;	// error. "0 = 10"
	goo() = 10;	// ok	  "x = 10"

	
	
	//---------------------------

	// Quiz #1
	const int c = 10;
	c = 20;	// error.    c는 lvalue ? rvalue ?
			// 이름이 있고, 단일식을 넘어 사용가능, 주소 구할수 있습니다.
			// lvalue 입니다.
			// "immutable lvalue" 입니다. 값을 변경할수 없는 lvalue

	// Quiz #2
	// 모든 rvalue 는 상수이다 ??
	// => 아닙니다. 문법적으로 왼쪽에 올수 없을뿐, 상수는 아닙니다.
	Point{ 1,1 }.x = 10;    // error
	Point{ 1,1 }.set_x(10); // ok. 임시객체도 멤버 함수로는 상태 변경 가능합니다.
}









