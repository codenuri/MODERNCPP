// 149
int main()
{
	int v1 = 0, v2 = 0;

	// 지역변수 캡쳐의 다양한 모양
	auto f1 = [v1, &v2](int a) { ... };	// v1은 값   캡쳐, v2는 참조 캡쳐
	auto f2 = [&v1, v2](int a) { ... }; // v1은 참조 캡쳐, v2는 값  캡쳐

	auto f3 = [=](int a) { ... };	// 모든 지역변수를 값 캡쳐
	auto f4 = [&](int a) { ... };	// 모든 지역변수를 참조 캡쳐

	auto f5 = [=, &v2](int a) { ... }; // 모든 지역변수를 값 캡쳐, 단 v2는 참조캡쳐
	auto f6 = [&,  v2](int a) { ... }; // 모든 지역변수를 참조 캡쳐, 단 v2는 값캡쳐
	auto f7 = [&, &v2](int a) { ... }; // error. 디폴트방식과 다른것만 표기해야 합니다.

	// main 지역변수 이름과 다른 이름으로 캡쳐
	// => 멤버 데이타 이름이 변경.. 
	auto f8 = [x = v1, &y = v2](int a) { x, y = 100; }; // main 의 v2 = 100

	std::string s = "ABC";

	auto f9 = [s1 = std::move(s)] { s1 사용};
			// std::string s1 = std::move(s)

	std::cout << s << std::endl; // ""   자원 이동됨.
}




