// C++11 ���� �߰��� constexpr

// constexpr : ������ �ð� ��� ���鶧 ���
// ���� const : readonly �� �ǹ�!!

int main()
{
	int n = 3;
	const int c1 = 3;
	const int c2 = n;

	constexpr int c3 = 3;
	constexpr int c4 = n;
}