// constexpr 3번 - constexpr if

// static if ( constexpr if 를 이렇게도 부릅니다.)

/*
// 아래 코드가 왜 에러인지 생각해 보세요 ?
class A
{
	int data;
public:
	void foo()
	{
		*data = 10;	// error. int 변수를 * 할수 없습니다.
	}
};
int main()
{
	A a;
}
*/

template<typename T>
class A
{
	T data;
public:
	void foo()
	{
		*data = 10;	
	}
};

int main()
{
	A<int> a;
}
