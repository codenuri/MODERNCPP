// 2_타입추론5-2.cpp
template<typename T> void f1(T  a, T  b) {}
template<typename T> void f2(T& a, T& b) {}

int main()
{
	// "apple"  : const char[6] 
	// "banana" : const char[7] 
	// => 크기가 다른 배열은 "다른 타입" 입니다.
	
	// 아래 코드에서 에러를 생각해 보세요

	f1("banana", "apple");	// ok
		// => 인자가 값 타입이므로, 배열전달 => 포인터로 받게 됩니다.
		// => 이런 현상의 "decay" 라고 합니다.
		// "banana" : const char[7] => const char*
		// "apple"  : const char[6] => const char*

	f2("banana", "apple");	// error
		// => 인자가 참조 타입이므로 배열 전달 => 배열로 받게 됩니다.
		// "banana" : const char[7]
		// "apple"  : const char[6]
		// => 1, 2 번째 인자로 같은 타입을 보내야 하는데, 다른 타입을 전달하므로
		//    error.

	f2("banana", "orange"); // ok 
}