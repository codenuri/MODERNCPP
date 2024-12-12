inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

template<typename T>
void foo(T f)
{
	bool b = f(1, 2); // A
}

int main()
{
	foo(cmp1);		// foo( bool(*)(int, int) ) ����
	foo(cmp2);		// foo( bool(*)(int, int) ) ���� => ���� ����. f(1,2) ġȯ �ȵ�
	foo(Less{});	// foo( Less )			f(1,2) ġȯ
	foo(Greater{});	// foo( Greater )		f(1,2) ġȯ
}
// �� �ڵ带 ���� �Ʒ� ������ ���� ������
// 1. foo �Լ��� � �����Ǿ������ ?		==> 3��
// 2. ������ foo ���� A �κ��� �ζ���ġȯ���θ� ������ ������
// 3. foo �� ������, ������ �Լ��� � ������� ?
//	  main, 
//    cmp1, cmp2,  => �ζ���ġȯ���θ� ���Ǿ��ٸ� ���� �Լ��� ������ �ʿ�� ������
//						ȣ���� �뵵�� ���ǰ� �����Ƿ� �Լ��� �����Ǿ�� �Ѵ�.
//    Less::operator(), Greater::operator() => ġȯ�� �뵵�� ���ǹǷ�
//												������ �Լ��� �����ȵȴ�.
//												-Ob1 �� ���ٸ� ������ ������.

