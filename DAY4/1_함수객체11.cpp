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
	foo(cmp1);
	foo(cmp2);
	foo(Less{});
	foo(Greater{});
}
// �� �ڵ带 ���� �Ʒ� ������ ���� ������
// 1. foo �Լ��� � �����Ǿ������ ?
// 2. ������ foo ���� A �κ��� �ζ���ġȯ���θ� ������ ������
// 3. foo �� ������, ������ �Լ��� � ������� ?
