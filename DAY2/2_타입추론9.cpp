#include <iostream>

int x = 0;

int& foo(int n, double d) { return x; }

int main()
{
	auto ret1 = foo(1, 3.4); // auto 는 우변의 참조를 제거하고 결정되므로
//	int  ret1 = foo(1, 3.4); // 이렇게 결정됩니다.

	// decltype(함수 호출식) : 함수 호출의 결과로 나오는 타입(반환타입)조사
	//						  실제 함수가 호출되는 것은 아니고 컴파일시간에
	//						  함수 선언문을 보고 타입 결정					
	decltype( foo(1, 3.4) ) ret2 = foo(1, 3.4);
//  int& ret2 = foo(1, 3.4)

	// 그런데, 위 코드는 "함수 호출식이 2번" 나타나므로 복잡해 보입니다.
	// 그래서 C++14 부터 "dectlype(auto)" 제공 
	// => auto 자리에 우변을 넣어달라
	// => 또는, 우변으로 추론하는데, 규칙은 auto 가 아닌 decltype 으로 해달라
	decltype(auto) ret3 = foo(1, 3.4);
}
