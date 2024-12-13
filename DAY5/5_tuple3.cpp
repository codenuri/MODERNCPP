// Step2. 값 한개 보관하기 

template<typename ... Types>
struct tuple
{
public:
	static constexpr int N = 0;
};

// tuple 사용시, 최소한 한개이상의 타입을 전달하는 경우를 위한
// 부분 특수화
template<typename T, typename ... Types>
struct tuple<T, Types...>
{
	T value;

	tuple() = default;
	tuple(const T& v) : value(v) {}

	static constexpr int N = 1;
};

int main()
{
	// primary 사용
	tuple<> t0;				
	
	// 아래 3개는 부분 특수화 버전 사용
	tuple<short> t1;
	tuple<double, short> t2;
	tuple<int, double, short> t3;
}
