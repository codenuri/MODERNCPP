// 3_함수객체4 -  137 page 제일 윗부분내용
// "함수 객체가 빠르다" 는 주제에 대한 이야기 

       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // 호출
	int n2 = Add2(1, 2); // 기계어 코드 치환, 호출하는 것보다 빠르게 동작 


	int(*f)(int, int) = &Add2;

//	if (사용자 입력 == 1) f = &Add1;

	f(1, 2);	// 호출
}

// 1. 인라인 함수는 컴파일 시간 문법이다.
// 2. 인라인 함수라도 "함수 포인터"에 담아서 사용하면 "치환될수 없다"
//    호출됩니다.
