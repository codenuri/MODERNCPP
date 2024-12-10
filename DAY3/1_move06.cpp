#include <iostream>
#include <vector>

// 핵심 : move 기능은 결국, 해당 클래스를 만든 사람이
//		  move 생성자를 만들어서 기능을 제공하는 것. 
//        std::string 이 move 를 지원하는 것은 
//        std::string 을 만든 사람이 move 생성자를 제공한것

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }
//	Object(Object&&)      { std::cout << "move" << std::endl; }
};

int main()
{
	// #1. move 생성자를 만들지 않은 클래스에 대해서 std::move() 사용했다면 ?
	// => 
	Object o1;
	Object o2 = std::move(o1);
			// static_cast<Object&&>(o1); 즉, rvalue 로 캐스팅 한것
			// 따라서
			// 1. move 생성자가 있다면 사용하고 
			// 2. move 생성자가 없다면 "복사 생성자 사용"
			//    (복사 생성자는 lvalue, rvalue 를 모두 받을수 있다.)


	// #2. primitive type 에 대해서 std::move 를 사용했다면 ?
	// =>
	int n1 = 10;
	int n2 = std::move(n1);
			// static_cast<int&&>(n1);
			// 아무런 효과 없습니다. 
			// int n2 = n1 가 동일

	int* p1 = new int;
	int* p2 = std::move(p1);
			// 포인터에 사용해서 move 효과 없습니다
			// p1 이 0이 되는것 아닙니다.




	// #3. STL 의 대부분 클래스는 move 생성자를 제공합니다.
	std::vector<int> v1 = { 1,2,3,4 };
	std::vector<int> v2 = std::move(v1);

	std::cout << v1.size() << std::endl;	// 0
}





