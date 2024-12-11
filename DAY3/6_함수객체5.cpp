#include <iostream>
#include <vector>
#include <algorithm>


// 일반 함수 : 동작은 있지만 상태가 없습니다.
// 함수 객체 : 동작뿐 아니라 상태도 가지고 있다(멤버 데이타가 있다는 의미)


bool foo(int n) { return n % 3 == 0; }




// 아래 클래스(함수객체) 잘 생각해 보세요

class IsDivide
{
	int value;
public:
	IsDivide(int v) : value(v) {}

	bool operator()(int n) 	{  return n % value == 0; }

	// 다른 멤버 함수 마음대로 추가 가능!!!
	void reset_value(int k) { value = k; }

	// operator()가 아니라 다른 함수로 하면 안되나요 ??
	bool check(int n) { return n % value == 0; }
};

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3; 

	IsDivide f(k);		// f 는 k 값을 보관하고 있습니다.
						// f 는 단항함수(인자가 한개인 함수)로 사용가능 합니다.

	bool ret1 = f(10);	// 10 % k == 0
	bool ret2 = f.check(10); // 같은의미!!!
							// 그런데, find_if 는 3번째 인자로 받은것에 대해
							// () 를 사용해서 호출하도록 설계되었습니다.
							// 그래서, 이런 다른 이름을 가지는 멤버 함수가 아닌
							// operator() 를 사용하도록 하는 것
							//"일반 함수와 동일한 호출 방법"

	// 결국 f 는 "k 값을 보관"하는 단항 함수

	auto p1 = std::find_if(v.begin(), v.end(), f);

	// 단, 한번 사용한다면 "임시객체가 효율적"
	auto p2 = std::find_if(v.begin(), v.end(), IsDivide{k} );
										// 결국 이코드는
										// 단항함수객체 + main 지역변수 k 를
										// 같이 전달하는 것 처럼 보입니다.!!


	std::cout << *p1 << std::endl; // 6


}



