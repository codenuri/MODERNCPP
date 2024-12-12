int main()
{
	// C++14 : generic lambda expression
	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	int n = 10;
	double d = 3.4;

	swap(n, d); // 에러 나는게 좋을까요 ? 에러 없는게 좋을까요 ?
}
