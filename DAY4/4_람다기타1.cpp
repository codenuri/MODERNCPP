// 7_람다기타1 - 150
class Test
{
	int data = 0;
public:
	void foo()		// void foo(Test* this)
	{
		// 멤버 데이타 사용 
		// auto f = [](int a) { return a + data; }; // error

		// 멤버 데이타 캡쳐
		// => 지역변수만 캡쳐 가능. 멤버 데이타는 지역변수 아님.
		// auto f = [data](int a) { return a + data; }; // error

		// this 도 결국 지역변수의 일종입니다.
		// 멤버 데이타에 접근하려면 this 를 캡쳐 하면 됩니다.
		// 아래 코드는 data 가 아닌 "객체의 주소(this) 를 캡쳐" 한것
		auto f = [this](int a) { return a + data; }; 
										// this->data 가 맞는 코드 지만
										// data 만 표기 해도 됩니다.

		// f1은 값 캡쳐 입니다.
		auto f1 = [this](int a) { data = a; };

		f1(100); // 원본 data가 변경될까요 ??

		std::cout << data << std::endl;
	}
};

int main()
{
	Test t;
	t.foo(); // foo(&t)
			 // 즉, 컴파일러에의해 객체가 함수의 인자로 전달되는 것
}

