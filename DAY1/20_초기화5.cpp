#include <vector>
#include <string>
#include <memory>

void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	// 아래 한줄의 코드는 되는게 좋을까요 ? 에러 나오는게 좋을까요 ?
	hoo("hello"); // 논리적으로 맞는 코드 입니다.
				  // 되야 합니다.
				  // 현재 잘 됩니다.
				  

	std::string s1("hello");  // ok
	std::string s2 = "hello"; // ok. 즉, string(const char*) 버전의 생성자는
							  //     explicit 가 아니라는 의미

	goo(10);	// 논리적으로 맞지 않습니다.
				// 안되는게 좋습니다.
				// 현재 컴파일 에러 입니다.
				
	std::vector<int> v1(10);	// ok
	std::vector<int> v2 = 10;	// error. 즉, vector(int) 버전의 생성자는
								//        explicit 라는 의미


	// 권장
	// => 인자가 한개인 생성자 만들때 "explicit" 를 붙일지 붙이지 않을지 꼭 고려하세요
	// => 요즘은 붙이는 것이 권장합니다.(안전성)





}





