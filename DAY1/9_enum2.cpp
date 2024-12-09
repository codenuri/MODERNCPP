
// C/C++98 ������ enum 
// enum COLOR { red = 0, green = 1, blue = 2 };


// C++11 ���� ���γ����� enum ���� 
enum class COLOR { red = 0, green = 1, blue = 2 };


int main()
{
//	int n1 = red;			// error. COLOR ��� �̸� �ʿ�
//	int n2 = COLOR::red;	// error. int Ÿ���� �ƴ� COLOR Ÿ��
							//        int Ÿ������ �Ͻ��� ��ȯ �ȵ�
	COLOR c1 = COLOR::red;  // ok
//	COLOR c2 = red;			// error. COLOR �ʿ�

	// ĳ�����ϸ� int Ÿ������ ��ȯ �����մϴ�.
	int n = static_cast<int>(COLOR::red);
}

// C++98 ���� �Լ�
void foo(int color) {}
foo(red);	// ok. red�� enum ���
foo(-100);	// �߸� ��������� ���� �ƴ�.


// C++11 ����
void foo(COLOR c) {}
foo(COLOR::red); // ok
foo(100); // error. int �� COLOR Ÿ�� �ƴ�.