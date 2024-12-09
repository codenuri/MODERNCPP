// auto - 68 page 배울때 자세히
// 지금은 소개만. 

int main()
{
	int n1 = 0;

	// auto : 우변의 표현식으로 좌변의 타입을 결정.
	//		  컴파일러가 컴파일 시간에 결정 
	//        실행시 오버헤드는 없음. 
	auto a1 = 3;		// => int a1 = 3;
	auto a2 = 3.4;		// => double a2 = 3.4;

	const int c = 0;
	auto a3 = c; // const int a3 = c; // 1
				 // int a3 = c;		  // 2 => 답...!!
}


// 빌드 하는 법
// Ctrl + F5
