// chronometry.h 파일 추가 하세요 - git 에 있는 소스 복사 하세요
// 1_함수객체10.cpp -
#include <vector>
#include <algorithm>
#include "chronometry.h"


inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };



const std::size_t count = 1000000;

std::vector<int> v1;
std::vector<int> v2;

void init()
{
	// v1, v2 를 동일 데이타로 채움니다.
	v1.reserve(count);
	v2.reserve(count);

	for (int i = 0; i < count; i++)
	{
		int n = rand();
		v1.push_back(n);
		v2.push_back(n);
	}
}

void ex1()
{
	// 비교정책으로 일반함수를 사용해서 sort
	std::sort(v1.begin(), v1.end(), cmp1);
	std::sort(v1.begin(), v1.end(), cmp2);
}
void ex2()
{
	// 비교정책으로 함수객체를 사용해서 sort
	std::sort(v2.begin(), v2.end(), Less{});
	std::sort(v2.begin(), v2.end(), Greater{});
}

int main()
{
	init();

	chronometry(ex2);
	chronometry(ex1);

	chronometry(ex1);
	chronometry(ex2);

	chronometry(ex1);
	chronometry(ex2);

}

// 디버그 빌드  : 인라인 치환이 적용되지 않습니다
// Release 빌드 : 인라인 치환이 적용됩니다.