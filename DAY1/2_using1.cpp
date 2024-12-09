// 11 page
// 
// C 스타일 코드 - typedef 
// typedef int DWORD;
// typedef void(*F)(); 

// 아래 2줄이 위 2줄과 완전히 동일합니다.
// C++11 using alias
using DWORD = int;
using F = void(*)();

int main()
{
	DWORD n;	// int n
	F     f;	// void(*f)();
}
