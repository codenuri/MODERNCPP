template<typename T> void f4(T&& a)
{
}

int main()
{
	int n = 3;

	// #1. Ÿ���� ���� �����ϴ� ���
	f4<int>(3 );	// T = int		T&& = int&&					f4(int&& a)
	f4<int&>(n );	// T = int&		T&& = int&  && => int&		f4(int& a)
	f4<int&&>(3 );	// T = int&&	T&& = int&& && => int&&		f4(int&& a)


	// #2. Ÿ���� �������� ���� ���
	// => �Լ� ���ڸ� ���� T �� Ÿ���� �����ؼ� �Լ��� ����
	f4(n);	// n �� int Ÿ���̹Ƿ� T = int �� �����ϸ�, f4(int&& a) ����
			// => �׷���, f4(int&&) �� lvalue �� ������ �����Ƿ� error.
			// 
			// �׷���, T = int& �� �����ߴٸ� f4(int& a) �Լ��� �����ǹǷ�
			// => f4(n) �� ������ �ƴϴ�.

	f4(3);	// 3�� int, T=int �� ����, f4(int&&) �Լ� ����
			// => ok.. ���� ����. 
}

// ����, ���ø��� Ÿ�� �߷�
template<typename T> void foo1(T a) {}
template<typename T> void foo2(T& a) {}
template<typename T> void foo3(T&& a) {}
int n = 3;
foo1(n);	// T = int
foo2(n);	// T = int
foo3(n);	// T = int&   <== �ٽ�  ���迡 ���ɴϴ�. �� �ܿ� �μ���