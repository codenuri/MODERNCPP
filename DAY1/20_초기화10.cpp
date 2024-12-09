// 1_초기화10
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };


	// 아래 2줄의 차이점은 ?
	std::vector<int> v3(10, 2); // 10개 요소를 2로 초기화. v3.size() 는 10
								// vector(int, int) 생성자

	std::vector<int> v4{10, 2};	// 2개를 10, 2 로 초기화. v4.size() 는 2
								// vector(std::initializer_list<int>)


	// 아래 코드에서 에러는 ?
	std::vector<int> v5 = 10;	// error. 
								// vector(int) 생성자는 explicit 이므로!!

	std::vector<int> v6 = {10}; // ok
								// vector(std::initializer_list<int>) 생성자는
								// explicit 가 아닙니다.
}




