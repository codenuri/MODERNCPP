// 14_override  - 44 page

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
	// 가상 함수 재정의시 실수(오타)
	// => 하지만 컴파일 해도 에러가 나지 않습니다.
	// => 컴파일러가 다른 가상함수를 추가한 것이라고 생각 합니다.
//	virtual void fooo() {}
//	virtual void goo(double a) {}
//	virtual void hoo() const  {}

	// 위 문제를 해결하기 위해 C++11 에서 override  키워드 등장
	// => 새로운 함수가 아니라 기반 클래스 가상함수를 다시 만드는 것이라고 알려주는것
	virtual void fooo()        override {}
	virtual void goo(double a) override {}
	virtual void hoo() const   override {}
};


int main()
{
}
