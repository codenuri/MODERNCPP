#include <iostream>

struct Base
{
	int value = 10;
};
struct Derived : public Base
{
	// 기반 클래스 멤버와 동일한 이름의 
	// 멤버 데이타를 추가할수 있습니다.
	int value = 20;
};
int main()
{
	Derived d;

	std::cout << d.value << std::endl; // 20


	// 기반 클래스에서 상속된 멤버에 접근하려면
	// 기반 클래스의 참조 타입으로 캐스팅 하면 됩니다
	std::cout << static_cast<Base&>(d).value << std::endl; // 10

	// 주의 : 값 캐스팅하면 안됩니다 => 임시객체의 생성
	//        반드시 참조 캐스팅 해야 합니다.


}
