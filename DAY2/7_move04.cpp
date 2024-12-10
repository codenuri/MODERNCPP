#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	// 일반적인 경우의 복사 생성자 구현 ( deep copy 로 구현)
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];

		strcpy_s(name, strlen(c.name) + 1, c.name);
	}

	// 인자가 rvalue(임시객체)일때의 구현
	// Cat&&      : rvalue 만 받을수 있다.
	// const Cat& : lvalue, rvalue 를 모두 받을수 있지만, 위 Cat&& 버전이 있다면
	//				rvalue 는 Cat&& 버전 사용
	// 
	// => 아래 함수는 "복사 생성자"가 아닌 "move 생성자"라고 합니다.
	Cat(Cat&& c) : age(c.age)
	{
		name = c.name; // 

		c.name = nullptr; // 임시객체가 자원을 포기하도록
						  // 이작업을 하려면 임시객체를 const 없이 받을수 있어야 한다.
						  // 그래서, "상수성 없이 임시객체를 가리키는 문법"이 필요 했다.
	}
};


Cat foo()
{
	Cat c("yaong", 2);
	return c;
}

int main()
{
	Cat c1 = foo(); // 이 한줄에 대해서 생각해 봅시다.
					// 메모리 구조, 성능에 대해서
}



