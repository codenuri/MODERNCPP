// 2_forwarding_reference4-1.cpp
// ����

// �Լ� ���ڷ� ���Ǵ� ���۷����� �ǹ�

fn(int&) : int Ÿ�� lvalue �� ������ �ִ�.
fn(int&&) : int Ÿ�� rvalue �� ������ �ִ�.
fn(T&) : ���� Ÿ�� lvalue �� ������ �ִ�. (�ش� Ÿ���� lvalue& �Լ��� ����)

fn(T&&) : ���� Ÿ�� lvalue, rvalue �� ��� ������ �ִ�.
		  => �Ѱ� �Լ����� ��� �޴� ���� �ƴ϶�, ���ø� �̹Ƿ�
		  => �������ִ� �Լ��� �����ϰڴٴ� ��. 
		  => ������ �Լ��� ��� call by value �� �ƴ� call by reference
			 fn(int&) �Ǵ� fn(int&&)

// �Ʒ� ���� �ܿ� �μ���. ���迡 ���ɴϴ�.
template<typename T> fn(T&& arg) {} ����

int n = 3;
fn(n), lvalue ���� : T = int&, T&&=int& && => int&   fn(int&)   �Լ� ����
fn(3), rvalue ���� : T = int,  T&&=int&&             fn(int&&)  �Լ� ����


// 