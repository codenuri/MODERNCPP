#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	// move �� �����ϴ� ������ �����
	// => ��, T Ÿ���� std::string �� ���� Ÿ��(�Ǵ� ��ȯ ���� Ÿ���϶���)
	//    ����ϴ� ���� ���� �մϴ�
	// => enable_if ����� ����ؾ� �ϴµ�,,,
	//   �����ڴ� ��ȯ Ÿ���� �����ϴ�.
	//   �׷��� �̷� ���� �Լ� ���ڳ� ���ø� ���ڿ� ���
	//   => �Ϲ������δ� ���ø� ����
	template<typename T,
			 typename T2 = std::enable_if_t< std::is_convertible_v<T, std::string>>>

	People(T&& n) : name(std::forward<T>(n)) {}
};

int main()
{

	std::string s = "kim";
	People p1(std::move(s));

	People p2(3.4); // enable_if �� ���ٸ� �����ڰ� ����� ����, "name = 3.4" ���� ����
					// enable_if �� �ִٸ�
					// "���ø� => ������" ������ ���߱� ������
					// ������ ���ٰ� ����. 

}