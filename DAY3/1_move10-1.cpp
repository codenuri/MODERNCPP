#include <iostream>
#include <string>

// �ڵ� ���� ��Ģ.
// ��Ģ #2. ����ڰ� ��������ڸ� ������ ���
// => �����Ϸ��� �̵��迭�� �Լ��� �������� �ʽ��ϴ�

// => std::move() ����, ����ڰ� ���� ���� ������ ȣ��. 

struct Object
{
	std::string name;

	Object() = default;
	//-------------------------------	
	Object(const Object& other) : name(other.name)
	{
		std::cout << "copy\n";
	}
};



int main()
{
	Object o1; o1.name = "object#1";
	Object o2; o2.name = "object#2";

	Object o3 = o1;
	Object o4 = std::move(o2); // �����Ϸ��� ���� move ������ �����Ƿ�
							   // ����ڰ� ���� ���� ������ ���

	std::cout << o1.name << std::endl; // "object#1"
	std::cout << o2.name << std::endl; // "object#2"
}
