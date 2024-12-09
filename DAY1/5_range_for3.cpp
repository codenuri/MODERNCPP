#include <iostream>
#include <vector>

// 아래 클래스에 대해서 잘생각해 보세요
template<typename T> 
class take_view
{
	T& rng;
	int cnt;
public:
	take_view(T& r, int c) : rng(r), cnt(c) {}

	auto begin() { return rng.begin(); }
	auto end() { return rng.begin() + cnt; }
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
	take_view< std::vector<int> > tv(v, 3);

	for (int e : tv)
	{
		std::cout << e << ", ";
	}
}















