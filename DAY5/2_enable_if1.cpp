// 6_enable_if1.cpp

// 아래 템플릿이 이미 C++11 표준에 있습니다. 구현도 동일.. 
template<bool, typename T = void > struct enable_if
{
	using type = T;
};
// 1번째 인자가 false 인 경우를 위한 부분 특수화
template<typename T> struct enable_if<false, T> 
{
	// type 이 없다는 것이 핵심 
};

int main()
{
	// 아래 코드에서 각 변수의 타입은 ?
	enable_if<true, int>::type  n1; // int  n1
	enable_if<true>::type       n2; // void n2. error. void 타입 변수는 만들수없다.
	enable_if<false, int>::type n3; // error. "::type" 이 없다.
}

// 정리. 아래 외워 두세요
// enable_if<true, "타입">::type  => 결국 "타입" 입니다.
// enable_if<true>::type	      => void 입니다.
// 
// enable_if<false, "타입">::type => "::type" 이 없습니다.
// enable_if<false>::type         => "::type" 이 없습니다.