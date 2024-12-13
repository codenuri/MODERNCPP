// Step3. ��� �� �����ϱ� - �ٽ�!!!

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
	tuple<> t0;					  // primary ���, �����ϴ� ����Ÿ ����. 
	tuple<			   short> t1; // short
	tuple<	   double, short> t2; // double ����
	tuple<int, double, short> t3; // int ����
}
