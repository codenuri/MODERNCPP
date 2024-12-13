// Step3. 모든 값 보관하기 - 핵심!!!

template<typename ... Types>
struct tuple
{
public:
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	T value;

	tuple() = default;
	tuple(const T& v) : value(v) {}

	static constexpr int N = 1;
};

int main()
{
	tuple<> t0;					  // primary 사용, 보관하는 데이타 없음. 
	tuple<			   short> t1; // short
	tuple<	   double, short> t2; // double 보관
	tuple<int, double, short> t3; // int 보관
}
