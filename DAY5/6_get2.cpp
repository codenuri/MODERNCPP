// get2.cpp
#include <iostream>
#include "tuple.h"

int main()
{
	//	tuple<> t0;					  // primary ���, �����ϴ� ����Ÿ ����. 
	// 
	//	tuple<			   short> t1;			// short ���� 5    2��° �θ�
	// 
	//	tuple<	   double, short> t2;			// double ���� 3.4  1��° �θ�
	// 
	//	tuple<int, double, short> t3(1, 3.4, 5); // int ����  1		0��° �θ�


	tuple<int, double, short> t(1, 3.4, 5);

	
	std::cout << t.value << std::endl; // 1

	std::cout << static_cast<tuple<double, short>&>(t).value << std::endl; // 3.4 ������ �غ�����

	std::cout << static_cast<tuple<short>&>(t).value << std::endl; // 5 ������ �غ�����
	
	// �ٽ� 
	// => �ᱹ tuple �� ������ �� ��ҿ� �����ϴ� ���� ĳ����(������ �ð�)�ϻ��Դϴ�.
	// => ����, ����� �������� �����ϴ�.
	
	// ���� get�� ����� ������ ���ô�.

	int n = get<0>(t);

	get<0>(t) = 10;
}

template<int N, typename TP >
Ʃ��TP�� N��° ����� Ÿ��&
get( TP& tp )
{
	return static_cast<Ʃ��TP�� N��°��Ҹ� �����ϴ� �θ�Ÿ��&>(tp).value;
}
// �� �ѱ��� �ڵ�� �����ϸ� �ϼ��˴ϴ�.
// �ᱹ Ʃ�� TP ���� 
// => N ��° ����� Ÿ�԰�
// => N ��° ��� Ŭ������ Ÿ���� ���Ҽ� ������ �˴ϴ�.
// => ����, get �� �ᱹ ĳ�����̹Ƿ� �������� �����ϴ�.
