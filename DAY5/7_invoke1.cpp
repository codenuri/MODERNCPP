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
//	f2(10); // 될까요 ? error. 객체가 없습니다.
			// 멤버 함수는 객체가 있어야 호출가능합니다.

//	Object obj;
//	obj.f2(10); // error. obj 안에는 f2 라는 멤버는 없습니다.
				// f2 는 함수 포인터 이지 멤버는 아닙니다.

	// 핵심 5. pointer to member 라는 연산자( .*, ->* )
	// => 멤버 포인터를 사용해서 멤버 호출할때 사용

	Object obj;
//	obj.*f2(10); // 연산자 우선 순위 문제로 에러
				 // .* 연산자 보다 ( 연산자가 우선순위가 높습니다.

	(obj.*f2)(10); // ok.. 이코드 멤버함수 포인터로 함수를 호출하는 코드입니다.

}
