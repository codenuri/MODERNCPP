#include <iostream>
#include <string>
#include <vector>

// move 개념 

int main()
{
	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

	std::cout << "s1 버퍼 : " << (void*)s1.data() << std::endl;
	std::cout << "s2 버퍼 : " << (void*)s2.data() << std::endl;
	std::cout << "==================================\n";

	// 아래 2줄의 메모리 차이점을 이해 해야 합니다.
	std::string s3 = s1; // 복사 생성자 호출
						 // "깊은 복사"로 구현
						 // s3, s1 은 각각 자신의 자원(문자열)을 가지게 됨.

	std::cout << "s1 버퍼 : " << (void*)s1.data() << std::endl;
	std::cout << "s3 버퍼 : " << (void*)s3.data() << std::endl;


	std::cout << "==================================\n";
	std::string s4 = std::move(s2);
					// s2 가 사용하던 자원(메모리)를
					// s4 로 이동(move)
					// s2 자신은 자원(메모리)가 없다.!!

	std::cout << "s2 버퍼 : " << (void*)s2.data() << std::endl;
	std::cout << "s4 버퍼 : " << (void*)s4.data() << std::endl;

	std::cout << s1 << std::endl;	// "hello"
	std::cout << s2 << std::endl;	// ""


}

