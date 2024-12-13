// �ϼ��� �ڵ� 
// => tuple<int, double, short>,  tuple< double, short>
//    ��, ��Ӱ����� ���� Ŭ������ �����ǹǷ� �ڵ� �޸� �������� �ʳ��� ?
// => tuple ��ü�� ����� ���� ����,
//    �����Ϸ� ����ȭ�� ���ؼ�, ��κ��� �������� ���� �˴ϴ�.
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
