// 7_생성자상속1 - 26page
class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};
class Derived : public Base
{
public:
	// C++98/03 : 생성자는 상속되지 않는다.
	// 그래서 C++ 98 시절에는 아래 처럼 Derived 생성자를 만들어서 Base 에 전달했습니다.
//	Derived() {}
//	Derived(int n) : Base(n) {}

	// C++11 부터는 아래 처럼하면 생성자도 상속받을수 있습니다.
	// => 위처럼 인자를 단지 기반 클래스 생성자로 보내기만 할때 사용합니다
	using Base::Base;	// using 클래스이름::생성자이름
						// 생성자 상속 문법
};

int main()
{
	// 아래 2줄을 생각해 보세요
	Derived d1;
	Derived d2(5);	// error. Derived 에는 int 한개 생성자가 없습니다.
					// 단, 생성자 상속을 받았다면 ok..!
}
