#include <iostream>
#include <algorithm>
#include <functional> // C++ǥ�ؿ��� �����ϴ� �پ��� �Լ� ��ü�� - C++98
// std::less<>, std::greater<>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };


	// �Ʒ� �ڵ忡 ���ؼ� �� �غ����� ( ������ ã�� ������ )
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
}





