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
}









