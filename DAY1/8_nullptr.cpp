// 8_nullptr - 29page

int main()
{
	// C/C++98 시절
	int  n1 = 0;
	int* p1 = 0;	// 포인터 초기화에 0 사용

	// C++11 이후는 포인터 초기화에 0대신 nullptr 권장
	int* p2 = nullptr; // 좋은 코드
	int* p3 = 0;       // 권장 안함..

	int n2 = nullptr; // error. nullptr 은 포인터 초기화에만 사용
}
