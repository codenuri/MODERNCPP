//8_nullptr3
#include <iostream>

int main()
{
	// literal : 3, 3.4 와 같이 코드 안에서 사용되는 "값"
	// literal 과 타입
	3;		// int
	3.4;	// double
	"hello";// const char[6]

	false;	// bool 타입. false 는 bool 타입의 값이고, 키워드.. 

	nullptr;// std::nullptr_t 라는 타입입니다.
			// std::nullptr_t 타입은 모든 종류의 포인터로 암시적 형변환 된다는
			// 문법이 있습니다.

	std::nullptr_t a = nullptr;

	// 이제 a 는 nullptr 처럼 포인터 초기화에 사용가능합니다.
	int* p1 = a;
	double* p2 = a;	// double* p2 = nullptr 과 동일한 의미. 
}



