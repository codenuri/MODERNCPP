#include <iostream>
#include <string>
#include <vector>

// 왜 move가 중요한가 ? - 101 page 아래 있습니다.

// 아래 코드는 복사에 의한 Swap 입니다.
// 자원(문장열)을 통째로 복사하게 되므로
// 느립니다.
/*
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
*/
// 아래 코드는 move 에 의한 Swap 구현 입니다.
// 위 코드 보다 훨씬 빠르게 동작합니다.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}

// move 개념에서 개발자가 알아야 하는 것
// #1. swap 등의 알고리즘 작성시 std::move() 적절히 사용하면 성능 향상을 볼수 있습니다.

// #2. std::string 이 아닌 사용자가 만드는 타입(Point, Rect 등)이 move 개념을 지원하려면
//     어떻게 해야 하는가 ? => 까다롭습니다.

// #3. setter 나 생성자 등을 만들때 move 를 지원하는 방법 - 약간 어려운 주제. 
