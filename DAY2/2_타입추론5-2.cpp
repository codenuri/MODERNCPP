// 2_Ÿ���߷�5-2.cpp
template<typename T> void f1(T  a, T  b) {}
template<typename T> void f2(T& a, T& b) {}

int main()
{
	// "apple"  : const char[6] 
	// "banana" : const char[7] 
	// => ũ�Ⱑ �ٸ� �迭�� "�ٸ� Ÿ��" �Դϴ�.
	
	// �Ʒ� �ڵ忡�� ������ ������ ������

	f1("banana", "apple");	// ok
		// => ���ڰ� �� Ÿ���̹Ƿ�, �迭���� => �����ͷ� �ް� �˴ϴ�.
		// => �̷� ������ "decay" ��� �մϴ�.
		// "banana" : const char[7] => const char*
		// "apple"  : const char[6] => const char*

	f2("banana", "apple");	// error
		// => ���ڰ� ���� Ÿ���̹Ƿ� �迭 ���� => �迭�� �ް� �˴ϴ�.
		// "banana" : const char[7]
		// "apple"  : const char[6]
		// => 1, 2 ��° ���ڷ� ���� Ÿ���� ������ �ϴµ�, �ٸ� Ÿ���� �����ϹǷ�
		//    error.

	f2("banana", "orange"); // ok 
}