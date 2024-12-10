#include <iostream>
#include <cstring>

// std::move() - 100 page

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name,  n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name,  c.name);
		std::cout << "����" << std::endl;
	}

	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "�̵�" << std::endl;
	}
};
Cat foo()
{
	Cat c("yaong", 3);
	return c;
}
int main()
{
	Cat c1("nabi", 2);

	// �Ʒ� �ڵ�� �̷л� "Cat c3 = �ӽð�ü;" �̹Ƿ� �̵� �����ڰ� ȣ��Ǿ�� �մϴ�.
	// => �׷���, ��κ��� �����Ϸ��� "�ӽð�ü����" ��� ����ȭ ����� ����ϹǷ� 
	// => �Ʒ� �ڵ�� �ӽð�ü�� ��� "�̵�"�� ������ �ʽ��ϴ�.
	Cat c3 = foo();		

	// �̰�� Ȯ���Ϸ��� "g++ �����Ϸ�����ϰ�, -fno-elide-constructors" ��� �ɼ��� ����ϼ���
	// => �ӽð�ü ���� ����ȭ ���� ����.!


	// ���� �ϽǶ�

	// "g++ �ҽ��̸�.cpp -std=c++11  -fno-elise-constructors" �� �����ϴµ�
	// #1. C++ ���� -std=c++11 �϶���  -std=c++17 �϶� �� �ϰ�
	// #2. -fno-elise-constructors �� �������� �������� �� ���� ������
	
}




