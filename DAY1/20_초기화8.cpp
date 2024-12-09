// 1_초기화8 - 62page
#include <iostream>
#include <initializer_list> // 핵심

// 초기화 주제에서 가장 중요한 핵심..
// => 반드시 알아야 합니다.

// std::initializer_list<int> 는 크기가 크지 않습니다.
// => const & 가 아닌 call by value 가 원칙 입니다.
void foo(std::initializer_list<int> e)
{
}
int main()
{
	// 핵심 #1. 아래코드의 메모리 구조 알아 두세요
	// 1. 우변 초기값을 배열과 동일한 형태로 메모리에 생성(익명의 배열이라고도 합니다)
	// 2. e 는 "포인터 2개(시작 과 끝)" 또는 "포인터한개(시작) 와 갯수" 로 되어 있습니다.
	std::initializer_list<int> e = { 1,2,3,4,5 };

	// 3. e 는 STL 의 기본인 begin(), end(), size()
	auto first = e.begin();

//	*first = 10; // error.  읽기 전용 반복자 입니다.

	// 4. 함수 인자로 std::initializer_list 를 사용하면 int 를 몇개라도 전달 가능합니다.
	foo(e);
	foo({ 1,2,3 });
	foo({ 1,2,3, 4, 5 }); // 마치 인자로 배열을 보내는것처럼 보입니다.
}


