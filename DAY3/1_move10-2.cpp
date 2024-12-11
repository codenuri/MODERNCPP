#include <iostream>
#include <string>

// �ڵ� ���� ��Ģ.
// ��Ģ #3. ����ڰ� �̵������ڸ� ������ ���
// => �����Ϸ��� ���� �����ڸ� �������� �ʽ��ϴ�.(��Ȯ���� ����(delete) �մϴ�)
// => �̰��, ���� �����ڰ� �ʿ��� �ڵ尡 �ִٸ� ������ ����!!
// move �����ڰ� ��� ���� �����ڸ� ����Ҽ� ������
// ���� �����ڰ� ��� �̵� �����ڸ� ����Ҽ��� ����.

// �� ��쵵, ���� �����ڸ� "=default" �� ��û�Ҽ��� �ֽ��ϴ�.

struct Object
{
	std::string name;

	Object() = default;
	//-------------------------------	
	Object(Object&& other) noexcept : name(std::move(other.name))
	{
		std::cout << "move\n";
	}

};

int main()
{
	Object o1; o1.name = "object#1";
	Object o2; o2.name = "object#2";

	Object o3 = o1;	// error
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; 
	std::cout << o2.name << std::endl; 
}
