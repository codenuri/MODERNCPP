// get2.cpp
#include <iostream>
#include "tuple.h"

int main()
{
	//	tuple<> t0;					  // primary ���, �����ϴ� ����Ÿ ����. 
	//	tuple<			   short> t1; // short
	//	tuple<	   double, short> t2; // double ����
	//	tuple<int, double, short> t3; // int ����

	tuple<int, double, short> t(1, 3.4, 5);

	
	std::cout << t.value << std::endl; // �� ������ ������ ������

	std::cout << t.value << std::endl; // 3.4 ������ �غ�����

	std::cout << t.value << std::endl; // 5 ������ �غ�����
}

