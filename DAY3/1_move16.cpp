#include <iostream>
#include <string>
#include <vector>

// 핵심 : Setter 만들기 #1

class People
{
private:
	std::string name;
	int age;

public:
	
	// move 지원 setter 만들기

	// 방법 #1. 2개의 setter 
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n) { name = std::move(n); }


	// 방법 #2. T&& 를 사용하면 "방법#1" 을 자동생성할수 있습니다.
	template<typename T>
	void set_name(T&& n)
	{
		// 다음중 맞는 것은 ?
//		name = n;					// 1. 항상 복사
//		name = std::move(n);		// 2. 항상 이동
		name = std::forward<T>(n);	// 3. set_name(lvalue) 라면 복사
									//    set_name(rvalue) 라면 이동
	}

	// 방법 #1 이 좋을까요 ? => 2개의 함수로 main 의 3가지 모두 해결 
	// 방법 #2 가 좋을까요 ? => main 함수의 A, B, C 에 대해서 
	//							3개의 set_name() 생성. 	
	// 
	
	// 다양한 관점에서 "방법 #1" 이 좋습니다
	// => 그런데, 인자가 2개 이상인 setter 라면!! - 다음 예제
};

int main()
{
	People p;

	std::string s1 = "kim";
	const std::string s2 = "kim";
	std::string s3 = "lee";

	p.set_name(s1);				// A	
	p.set_name(s2);				// B
	p.set_name(std::move(s3));	// C


}








