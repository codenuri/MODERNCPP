// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();

	if (ret == 0)
	{
	}
	// 위코드는 C++17 부터 아래 처럼해도 됩니다.
	// 전통적인 if            : if ( 조건식 )
	// 초기화 구문을 가지는 if : if ( 초기화구문; 조건식)

	if (int ret2 = foo(); ret2 == 0)
	{

	} // <= ret2 이 지점에서 파괴.

	// switch 도 초기화 구문 가능합니다
	switch (int n = foo(); n)
	{
	case 1:break;
	case 2:break;
	}

	// C++20 부터는 range-for 도 초기화 구문 가능
	for (std::vector<int> v = { 1,2,3 }; int e : v)
	{

	}
}
