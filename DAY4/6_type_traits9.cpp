#include <iostream>
#include <type_traits>

struct Object
{
	Object() = default;
	Object(const Object&) { std::cout << "copy\n"; }
	Object(Object&&) noexcept { std::cout << "move\n"; }
};

// �Լ� ���ø� ���鶧 �Ʒ� 2���� �������� ��Ȯ�� �˾� �μ���
// ���ڷ� T&  ��� : lvalue �� �ްڴٴ� �ǵ�
// ���ڷ� T&& ��� : lvalue, rvalue ��� �ްڴٴ� �ǵ�. 

// std::move() �� 
// => lvalue �� rvalue �� ��� �޾Ƽ�
// => rvalue �� ĳ���� �ؼ� ��ȯ

template<typename T>
T&& xmove(T&& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	Object o1;

	Object o2 = std::move(o1);
	Object o3 = std::move(Object{}); 
	// �Ʒ� �ڵ�� ��� move ���;� �մϴ� �׷���..
	// => ������ �ذ�å�� �����ҽ�����.. 
	Object o4 = xmove(o2);			// copy
	Object o5 = xmove( Object{} );	// move
}
