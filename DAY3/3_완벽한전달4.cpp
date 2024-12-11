#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }


void hoo(int&& arg) {}

// main						chronometry						hoo(int&&)
// hoo(10) ==================================================> ok
// chronometry(10) =======> int&& arg = 10	
//							hoo(arg) ========================> error. arg�� lvalue		
//					�ذ�å  	hoo(static_cast<int&&>(arg)) ====> ok
// 	
template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F> void chronometry(F f, int&& arg)
{
//	f(arg);	// hoo(arg) �ε�, arg �� lvalue �̹Ƿ� hoo(int&) �� ã�� �ȴ�.
	f( static_cast<int&&>(arg) ); // ok

	// �ᱹ, chronometry(10) �� "10" �� rvalue ���µ�..
	// int&& arg = 10 ���� �����鼭 art �� lvalue �� �Ȱ�
	// �ٸ� �Լ��� �������� �ٽ� rvalue �� ĳ�����ؼ� ����
}

int main()
{
	hoo(10); 

	chronometry(hoo, 10); 
}
