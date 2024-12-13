#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	// move 를 지원하는 생성자 만들기
	// => 단, T 타입이 std::string 과 같은 타입(또는 변환 가능 타입일때만)
	//    사용하는 것이 안전 합니다
	// => enable_if 기술을 사용해야 하는데,,,
	//   생성자는 반환 타입이 없습니다.
	//   그래서 이런 경우는 함수 인자나 템플릿 인자에 사용
	//   => 일반적으로는 템플릿 인자
	template<typename T,
			 typename T2 = std::enable_if_t< std::is_convertible_v<T, std::string>>>

	People(T&& n) : name(std::forward<T>(n)) {}
};

int main()
{

	std::string s = "kim";
	People p1(std::move(s));

	People p2(3.4); // enable_if 가 없다면 생성자가 만들어 지고, "name = 3.4" 에서 에러
					// enable_if 가 있다면
					// "템플릿 => 생성자" 생성을 못했기 때문에
					// 생성자 없다고 에러. 

}