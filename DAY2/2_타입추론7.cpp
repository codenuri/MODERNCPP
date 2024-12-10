// decltype 규칙 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };


	// 규칙 #2. id-expression 이 아닌 경우
	// => () 안의 표현식이 , "이름 + 연산자" 등이 있을때
	// => 해당 표현식이 등호의 왼쪽에 올수 있다면 참조 타입
	//						  왼쪽에 올수 없다면 값 타입

	decltype(*p)	d2;		// "*p = 10" 가 가능하다. 
							// int& d2;			초기값 없으므로 error

	decltype(x[0])	d3;		// "x[0]=10" 가능.	int& d3

	decltype(n) d;			// "n = 10" 가능하지만, 심볼의 이름만 있으므로 규칙 #1 적용
							// int d;
					

	decltype(n + n) d4;		// "n + n = 10" 가 될수 없다.  int d4; 

	decltype(++n)   d5;		// "++n = 10" 가능하다.        int& d5;
						
						
	decltype(n++)   d6;		// "n++ = 10" error.			int d6;
			
}

// 정리
// 규칙 #1. decltype(변수이름만) : 변수 선언을 조사해서 동일 타입으로 결정
// 규칙 #2. decltype(변수이름+다른 코드) : ()안의 표현식이 등호의 왼쪽에 올수 있다면 참조타입
//														등호의 왼쪽에 올수 없다면 값타입

