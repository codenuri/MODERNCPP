// 2_타입추론5-2.cpp
template<typename T> void f1(T  a, T  b) {}
template<typename T> void f2(T& a, T& b) {}

int main()
{
	// 아래 코드에서 에러를 생각해 보세요

	f1("banana", "apple");
	f2("banana", "apple");
}