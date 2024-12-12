#include <iostream>
#include <vector>
#include <algorithm>

struct People
{
	// name, addr
	int age;
	People(int a) : age(a) {}
};

int main()
{
	std::vector<People> v;
	v.emplace_back(10); // v.push_back(People(10)) 의미.
	v.emplace_back(20);
	v.emplace_back(15);

	// 캡쳐의 예제 입니다.
	
	int age = 15;

	// 나이가 age 인 사람을 찾고 싶다. ?
	auto ret = std::find_if(v.begin(), v.end(), 
		
		[age](const People& p) { return p.age == age; } );
}







