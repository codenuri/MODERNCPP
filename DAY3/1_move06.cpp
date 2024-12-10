#include <iostream>
#include <vector>

// �ٽ� : move ����� �ᱹ, �ش� Ŭ������ ���� �����
//		  move �����ڸ� ���� ����� �����ϴ� ��. 
//        std::string �� move �� �����ϴ� ���� 
//        std::string �� ���� ����� move �����ڸ� �����Ѱ�

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }
//	Object(Object&&)      { std::cout << "move" << std::endl; }
};

int main()
{
	// #1. move �����ڸ� ������ ���� Ŭ������ ���ؼ� std::move() ����ߴٸ� ?
	// => 
	Object o1;
	Object o2 = std::move(o1);
			// static_cast<Object&&>(o1); ��, rvalue �� ĳ���� �Ѱ�
			// ����
			// 1. move �����ڰ� �ִٸ� ����ϰ� 
			// 2. move �����ڰ� ���ٸ� "���� ������ ���"
			//    (���� �����ڴ� lvalue, rvalue �� ��� ������ �ִ�.)


	// #2. primitive type �� ���ؼ� std::move �� ����ߴٸ� ?
	// =>
	int n1 = 10;
	int n2 = std::move(n1);
			// static_cast<int&&>(n1);
			// �ƹ��� ȿ�� �����ϴ�. 
			// int n2 = n1 �� ����

	int* p1 = new int;
	int* p2 = std::move(p1);
			// �����Ϳ� ����ؼ� move ȿ�� �����ϴ�
			// p1 �� 0�� �Ǵ°� �ƴմϴ�.




	// #3. STL �� ��κ� Ŭ������ move �����ڸ� �����մϴ�.
	std::vector<int> v1 = { 1,2,3,4 };
	std::vector<int> v2 = std::move(v1);

	std::cout << v1.size() << std::endl;	// 0
}





