int main()
{
	int n = 10;
	double d = 3.4;

	// C++14 : generic lambda expression
	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	swap(n, d); // 에러 나는게 좋을까요 ? 에러 없는게 좋을까요 ?
				// 에러가 나는게 좋지만, 에러 아닙니다.
				// 위 swap 은 2개의 인자가 서로 다른 템플릿 이므로.
	//------------------------------------
	// C++20 : template lambda expression 문법 추가. 
	auto swap2 = []<typename T>(T& a, T& b) {   T tmp = std::move(a);
												a = std::move(b);
												b = std::move(tmp); };
	swap2(n, d); // error. 1, 2개의 인자 타입이 같아야 하는데..
				 //        다르기 때문에..

	// 1, 2의 인자가 서로 다른 타입이 되게 하려면 아래의 2가지 방법 가능하고
	// 결국 동일한 코드입니다.
	auto f1 = [](auto a, auto b) {  return a + b; };
	auto f2 = []<typename T1, typename T2>(T1 a, T2 b) {  return a + b; }
}
