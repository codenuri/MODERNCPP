// 완성된 코드 
// => tuple<int, double, short>,  tuple< double, short>
//    등, 상속계층에 따라 클래스가 생성되므로 코드 메모리 증가하지 않나요 ?
// => tuple 자체의 멤버가 별로 없고,
//    컴파일러 최적화에 의해서, 대부분의 오버헤드는 제거 됩니다.
template<typename ... Types>
struct tuple
{
public:
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using base = tuple<Types...>;

	T value;

	tuple() = default;
	tuple(const T& v, const Types& ... args) : value(v), base(args...) {}

	static constexpr int N = base::N + 1;
};

int main()
{
	tuple<int, double, short> t(1, 3.4, 5);
}
