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
constexpr std::remove_reference_t<T>&& xmove(T&& obj) noexcept 
{
	// �Ʒ� �ڵ�� �׻� rvalue �� ĳ�����ϴ� ���� �ƴմϴ�.
	// xmove(o2) �� ��� T = Object& �̰� T&& = Object& �̹Ƿ� �Ʒ� ĳ������
	// static_cast<Object&>(obj) �Դϴ�. ��, lvalue ĳ���� 
//	return static_cast<T&&>(obj);


	// move �� �׻� rvalue ĳ���� �Ǿ�� �մϴ�.
	// ���� ������ "T�ȿ� &�� ����" �Ǿ��ٴ°�
	// �ذ�å�� T���� ��� &�� �������� && �� ���̸� �˴ϴ�.
//	return static_cast< typename std::remove_reference<T>::type &&> (obj);
	return static_cast< std::remove_reference_t<T>&&> (obj);
}

int main()
{
	Object o1;

	Object o2 = std::move(o1);
	Object o3 = std::move(Object{});

	Object o4 = xmove(o2);			// T = Object&,  T&& = Object&  static_cast<Object&>(obj)
	Object o5 = xmove(Object{});	
}
