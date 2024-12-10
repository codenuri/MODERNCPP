// 1_후위반환타입1.cpp - 교재 73 page

// C/C++ 에서 전통적인 함수의 모양
int square1(int a)
{
	return a * a;
}

// C++11 부터 새로운 함수 모양이 도입되었습니다.
// => 후위 반환 타입(suffix return type, trailing return type) 이라는 문법
// => 아래 함수는 위와 완전히 동일합니다.
// => RUST, swift, haskell 등의 언어가 아래 처럼 반환 타입을 뒤에 적게 됩니다.
auto square2(int a) -> int
{
	return a * a;
}

int main()
{
	square1(3);
}
