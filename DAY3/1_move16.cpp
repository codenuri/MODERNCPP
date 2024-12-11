#include <iostream>
#include <string>
#include <vector>

// �ٽ� : Setter ����� #1

class People
{
private:
	std::string name;
	int age;

public:
	
	// move ���� setter �����

	// ��� #1. 2���� setter 
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n) { name = std::move(n); }


	// ��� #2. T&& �� ����ϸ� "���#1" �� �ڵ������Ҽ� �ֽ��ϴ�.
	template<typename T>
	void set_name(T&& n)
	{
		// ������ �´� ���� ?
//		name = n;					// 1. �׻� ����
//		name = std::move(n);		// 2. �׻� �̵�
		name = std::forward<T>(n);	// 3. set_name(lvalue) ��� ����
									//    set_name(rvalue) ��� �̵�
	}

	// ��� #1 �� ������� ? => 2���� �Լ��� main �� 3���� ��� �ذ� 
	// ��� #2 �� ������� ? => main �Լ��� A, B, C �� ���ؼ� 
	//							3���� set_name() ����. 	
	// 
	
	// �پ��� �������� "��� #1" �� �����ϴ�
	// => �׷���, ���ڰ� 2�� �̻��� setter ���!! - ���� ����
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








