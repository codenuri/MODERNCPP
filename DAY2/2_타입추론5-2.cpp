// 2_Ÿ���߷�5-2.cpp
template<typename T> void f1(T  a, T  b) {}
template<typename T> void f2(T& a, T& b) {}

int main()
{
	// �Ʒ� �ڵ忡�� ������ ������ ������

	f1("banana", "apple");
	f2("banana", "apple");
}