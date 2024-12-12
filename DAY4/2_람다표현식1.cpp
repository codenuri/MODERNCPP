#include <iostream>
#include <algorithm>
#include <functional> // C++표준에서 제공하는 다양한 함수 객체들 - C++98
					  // std::less<>, std::greater<>
#include <vector>

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// #1. 비교정책을 전달하지 않은 경우
	// => 오름 차순 정렬
	std::sort(v.begin(), v.end());


	// #2. 비교정책으로 일반 함수를 사용
	// => 비교 정책의 인라인 치환이 지원 안됨.
	std::sort(v.begin(), v.end(), cmp);


	// #3. 비교정책으로 함수객체를 사용

	std::less<int> f1;
	std::greater<int> f2;

	std::sort(v.begin(), v.end(), f2);

	// 한번만 사용한다면 임시객체 형태로!!
	std::sort(v.begin(), v.end(), std::less<int>{} );


	// #4. C++11 부터는 비교정책으로 람다 표현식 사용가능
	std::sort(v.begin(), v.end(), ? );
}





