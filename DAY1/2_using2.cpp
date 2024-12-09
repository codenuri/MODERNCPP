#include <unordered_set>

// std::unordered_set<int> 의 별명을 만들어 봅시다.
// #1. typedef 사용
// 아래 처럼 할수 밖에 없습니다.
typedef std::unordered_set<int> USET_I;
typedef std::unordered_set<double> USET_D;

// 그런데, std::unordered_set<int> 의 별명이 아닌(타입의 별명)
//         std::unordered_set      의 별명을 만들수 없을까요 ?(템플릿별명)

// 아래 처럼
// typedef std::unordered_set USET; // error.
								 // typedef 는 타입의 별명만 가능

// using 은 가능
template<typename T>
using USET = std::unordered_set<T>;

int main()
{
//	std::unordered_set<int>    s1;
	std::unordered_set<double> s2;

	USET<int>    s1;
	USET<double> s2;
}
