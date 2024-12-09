// constexpr 의 3가지 용도
// 1. constexpr 상수 - C++11 (constexpr2.cpp 참고)
// 2. constexpr 함수 - C++11 (현재 소스)
// 3. constexpr if   - C++17


// constexpr 함수
// => 반환 타입앞에 constexpr 을 붙이는 함수
// => "인자값을 컴파일 할때 알수 있고, 함수 호출 위치가
//    컴파일 할때 값을 알아야 되는 위치라면
//    함수 실행을 컴파일 할때 해달라.

constexpr int Factorial(int n)
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[ Factorial(5) ]; // ok. 컴파일 하면 "int arr1[120]" 이 됩니다.

//	int arr2[ Factorial(n) ]; // error. 인자값이 변수 이므로 컴파일 할때
							  //		인자 값을 알수 없습니다.
					

	int s1 = Factorial(n);	// ok. 컴파일 할때 실행해야 하는 위치가 아니다.
							//     인자가 변수 이므로 실행할때 함수 호출

	// 컴파일 시간에 수행할까요 ? 실행시간에 수행할까요 ?
	int           s2 = Factorial(5); // 컴파일러마다 다를수 있습니다.

	const int     s3 = Factorial(5); // 컴파일러마다 다를수 있습니다.

	constexpr int s4 = Factorial(5); // 반드시 컴파일 할때 수행되어야 합니다.

	constexpr int s5 = Factorial(n); // error. 인자가 변수 이므로
									 // 컴파일 할때 수행될수 없습니다.
}
