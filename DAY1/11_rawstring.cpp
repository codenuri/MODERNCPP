// 11_rawstring
#include <iostream>
#include <string>

int main()
{

	// '\' 문자 : 특수 문자 출력시 사용
	//           '\' 자체를 표현하려면 '\\' 로 해야
	std::string s1 = "\\\\.\\pipe\\server";

	// Raw String : '\' 를 특수 문자가 아닌 일반 문자열로 처리.
	// R : Raw String 임을 표기 하는 것
	// "( : 문자열 시작
	// )" : 문자열 종료
	std::string s2 = R"(\\.\pipe\server)";

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

	// 핵심 #1. ", ' 등을 표기하고 싶다.
	// => 그냥 적으면 됩니다.

	std::string s3 = R"(\\.\pi"pe\se'rver)";

	// 핵심 #2. )" 를 표기하고 싶다.
	std::string s3 = R"(\\.\pi)"pe\server)"; // error

	// 시작과 끝을 나타내는 토큰을 변경하면 됩니다.
	// 아래는  "(   )"  => "**(   )**" 로 변경한것
	std::string s3 = R"**(\\.\pi)"pe\server)**"; 
}
