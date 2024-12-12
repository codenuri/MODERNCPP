// 약간 어려운 이야기 입니다.

class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) { return a + b; }
};


int main()
{
	int(*f)(int, int) = CompilerGeneratedName{};


	// 람다 표현식을 함수 포인터에 담아서 사용할수 있습니다.
//	int(*f)(int, int) = [](int a, int b) {return a + b; };
						// 임시객체
//	int n = f(1, 2);
}












