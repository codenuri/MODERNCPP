// C++11 에서 추가된 constexpr

// constexpr : 컴파일 시간 상수 만들때 사용
// 기존 const : readonly 의 의미!!

int main()
{
	int n = 3;

	// const : 변수 선언후에는 값을 변경할수 없다는 의미
	//			readonly(immutable) variable 
	const int c1 = 3;	// ok 컴파일 할때 초기값을 알수도 있고
	const int c2 = n;	// ok 실행할때 결정될수도 있다.

	// constexpr : 컴파일 시간 상수를 만드는 것. 
	constexpr int c3 = 3;	// ok
	constexpr int c4 = n;	// error 

	c3 = 10; // error. 변경도 안됨.
}