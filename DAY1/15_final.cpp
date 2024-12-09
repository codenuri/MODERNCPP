class Base
{
public:
	virtual void foo() {}
	virtual void goo(int a) {}
	virtual void hoo() {}
};

class Derived : public Base
{
public:
	// final 용도 #1. 가상함수 뒤에 붙이는 경우
	// => 더이상 override 할수 없다는 의미
	virtual void foo()      override final {} 
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};

// final 용도 #2. 클래스 이름 뒤에 붙이면
// => 이 클래스에는 상속받을수 없다.(기반 클래스로 사용될수 없다.)
class Derived2 final : public Derived
{
public:
//	virtual void foo()      override {} // error. Derived 에서 final 로 선언!!
	virtual void goo(int a) override {} // ok
	virtual void hoo()      override {} // ok 
};

class Derived3 : public Derived2
{
};

int main()
{
}
