class Object
{
public:
	// Object obj;
	// obj.f1(10) 의 원리는 컴파일러가
	// f1(&obj, 10) 로 변경하는 것입니다.

	void mf1(int code) {}  // void f1(Object* this, int code) {}

	static void mf2(int code) {} // this 가 추가되지 않은 멤버 함수. 
};

void foo(int n) {}

int main()
{
	void(*f1)(int) = &foo;		  // ok
//	void(*f2)(int) = &Object::mf1; // error. 멤버 함수는 this가 추가됩니다.
	void(*f3)(int) = &Object::mf2; // ok. 

	// 핵심 1. 일반 함수 포인터에 non-static 멤버 함수의 주소를 담을수 없습니다.
	// 핵심 2. 일반 함수 포인터에     static 멤버 함수의 주소를 담을수 있습니다.

	// 핵심 3. 멤버 함수의 주소를 담는 포인터 만들기
	void(Object::*f2)(int) = &Object::mf1;


	// 핵심 4. 멤버 함수 포인터로 멤버 함수 호출 하기
	f2(10); // 될까요 ?
}
