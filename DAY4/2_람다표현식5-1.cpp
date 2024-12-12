#include <iostream>
#include <algorithm>
#include <functional> // C++ǥ�ؿ��� �����ϴ� �پ��� �Լ� ��ü�� - C++98
// std::less<>, std::greater<>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };


	// �Ʒ� �ڵ忡 ���ؼ� �� �غ����� ( ������ ã�� ������ )
	// => ������ ���� ǥ������ 3�� ��������� ��� �ٸ� Ÿ�� �Դϴ�.
	// => sort �Լ��� 3�� ���� �˴ϴ�
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// ������ ���� ǥ������ ������ ���ȴٸ� auto �� ��Ƽ� ����ϼ���
	// => �Ʒ� �ڵ�� "�Ѱ��� sort" �� ���� �˴ϴ�.
	auto cmp = [](int a, int b) { return a < b; };

	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);


	// �׷���, ����ǥ������ �ᱹ �Լ� ��ü�� ����� ���̰�
	// < �� ���� �Լ� ��ü�� �̹� std::less �� �ֽ��ϴ�.
	// ���� ��� std::less �� ����ϴ� �͵� ����. 

	std::less<int> f;
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), f);

	// �Ʒ� ó�� �ӽð�ü�� �ص� ���� �����ϴ�.
	// => ������ ȣ����� ��� ������ϴ�.( = default �� ��������͵�, ����ȭ!)
	std::sort(v.begin(), v.end(), std::less<int>{});
	std::sort(v.begin(), v.end(), std::less<int>{});
	std::sort(v.begin(), v.end(), std::less<int>{});
}






