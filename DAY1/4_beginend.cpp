// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

	// STL 사용시 반복자 꺼내기

	// #1. C++98 스타일
	// 단점 1. 코드가 복잡해 보인다.
	// 단점 2. 컨테이너 변경시, 좌변의 타입도 변경되어야 합니다.
//	std::vector<int>::iterator p1 = v.begin();
//	std::vector<int>::iterator p2 = v.end();

	// #2. C++11 권장사항
	// 1. 반복자의 정확한 타입을 사용하지 말고 auto 를 사용.
	// 2. 멤버 함수 begin 보다 일반함수 begin 이 유연성이 좋다. 
//	auto p1 = v.begin();	// error. raw array 에는 begin() 함수 없음.
//	auto p2 = v.end();

	auto p1 = std::begin(v);
	auto p2 = std::end(v);	// ok. 배열에는 멤버 함수는 없지만
							//	   배열을 함수인자로 보낼수는 있다.
							// 이경우 auto 는 int* 가 됩니다.!
}
