#include <iostream>
#include <vector>

template<typename ... Types>
void insert_vector(std::vector<int>& v, Types ... args)
{
	// args 의 모든 요소를 v에 넣어 보세요(push_back)
	( v.push_back(args) , ... );
	// pack 이름			op  ...	 => e1 op (e2 op( e3 op(... )
	// v.push_back(1), ( v.push_back(2), ( v.push_back(3) ... 
}

int main()
{
	std::vector<int> v;

	insert_vector(v, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	for (auto e : v)
		std::cout << e << ", ";
}

// 더 많은 예제는 구글에서 "C++ fold expression example" 하면
// 재미있는 코드 많이 있습니다.


