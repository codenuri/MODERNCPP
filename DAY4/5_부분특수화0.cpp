// 2_typename

struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p1 = 0;

template<typename T> void foo(T a)
{
	// 아래 코드에서 * 의 의미를 생각해 보세요
	Test::data  * p1; 
	Test::DWORD * p2; 

	
}
int main()
{
	Test t;
	foo(t);
}



