#include <iostream>

// shallow copy vs deep copy - 99page

// shallow copy : 컴파일러가 제공하는 복사 생성자가
//				  메모리 자체를 복사하지 못하고, 주소만 복사하게 되는 현상
// 해결책 : 사용자가 복사 생성자를 직접 만들어야 한다.

// Deep copy : 메모리 주소가 아닌 메모리 자체의 내용을 복사 하는 것. 


class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n)+1, n);
	}
	~Cat() { delete[] name; }

	// 사용자가 만드는 복사 생성자
	// 깊은 복사(Deep Copy) 로 구현한 복사 생성자
	Cat(const Cat& c) : age(c.age)
	{
		// 포인터가 아닌 멤버는 그냥 복사
		// age = c.age; // 이 위치 보다는 초기화 리스트가 좋습니다.

		name = new char[strlen(c.name) + 1];

		strcpy_s(name, strlen(c.name) + 1, c.name);
	}
};


int main()
{
	Cat c1("nabi", 2);


	Cat c2 = c1; 
}



