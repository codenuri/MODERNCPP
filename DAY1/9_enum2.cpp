
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
	COLOR c2 = red;			// error. COLOR �ʿ�
}





