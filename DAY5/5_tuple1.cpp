// 8_tuple1 - 245 page
#include <tuple>

int main()
{
	// pair : 서로 다른 타입 2개를 보관 - C++98
	std::pair<int, double> p(1, 2.3);

	// pair 요소 접근
	int n    = p.first;
	double d = p.second;


	// pair 로 3개 이상도 보관가능합니다.
	std::pair<int, std::pair<double, char>> p3(3, std::pair<double, char>(3.4, 'A'));

	int n1 = p3.first; // 3
	double d1 = p3.second.first; // 3.4
	char c1 = p3.second.second; // 'A'

	// 위처럼 생각하면 pair 에 몇개라도 보관가능합니다.
	// 그런데, 복잡해 보입니다.
	// 그래서, C++11 에서 std::tuple 이 도입됩니다.

	std::tuple<int, double, char>        t3(3, 3.4, 'A');
	std::tuple<int, double, char, short> t4(3, 3.4, 'A', 1);

	// 요소의 접근은 std::get<> 을 사용합니다.

	int n2 = std::get<0>(t3);

	std::get<0>(t3) = 10; // 좌변(lvalue)도 가능.. 

}
