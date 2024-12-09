// 11_rawstring
#include <iostream>
#include <string>

int main()
{

	// '\' 문자 : 특수 문자 출력시 사용
	//           '\' 자체를 표현하려면 '\\' 로 해야
	std::string s1 = "\\\\.\\pipe\\server";

	// Raw String : '\' 를 특수 문자가 아닌 일반 문자열로 처리.
	std::string s2 = R"(\\.\pipe\server)";

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}
