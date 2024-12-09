// C++11 ���� �߰��� constexpr

// constexpr : ������ �ð� ��� ���鶧 ���
// ���� const : readonly �� �ǹ�!!

int main()
{
	int n = 3;

	// const : ���� �����Ŀ��� ���� �����Ҽ� ���ٴ� �ǹ�
	//			readonly(immutable) variable 
	const int c1 = 3;	// ok ������ �Ҷ� �ʱⰪ�� �˼��� �ְ�
	const int c2 = n;	// ok �����Ҷ� �����ɼ��� �ִ�.

	// constexpr : ������ �ð� ����� ����� ��. 
	constexpr int c3 = 3;	// ok
	constexpr int c4 = n;	// error 

	c3 = 10; // error. ���浵 �ȵ�.
}