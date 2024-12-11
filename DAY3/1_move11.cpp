#include <iostream>
#include <string>
// rule of 5 : 소멸자, 복사생성자, 복사 대입연산자, 이동생성자, 이동 대입연산자
//			   를 만들어라!!

// rule of 0 : rule of 5 의 모든 함수를 전부 만들지 않으면
//				컴파일러가 모두 제공한다!! 최선의 코드

// 자원관리를 직접하지 말고, 자원 관리 클래스를 사용해라
// char* => std::string
// int*  => vector<int> 또는 std::shared_ptr<>
// FILE* => ofstream/ifstream 

// 아래 코드는 "복사" 와 "이동"을 모두 지원하는 완벽한 코드 입니다.
class Cat
{
//	char* name;
	std::string name;
	int   age;
public:
	Cat(const std::string& n, int a) : name(n), age(a)
	{
	}
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;	
	c2 = c1;		

	Cat c3 = std::move(c1);	
	c3 = std::move(c2);		

}




