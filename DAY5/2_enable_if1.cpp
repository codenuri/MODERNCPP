// 6_enable_if1.cpp

// 아래 템플릿이 이미 C++11 표준에 있습니다. 구현도 동일.. 
template<bool, typename T = void > struct enable_if
{
	using type = T;
};

template<typename T> struct enable_if<false, T> 
{
};

int main()
{
	// 아래 코드에서 각 변수의 타입은 ?
	enable_if<true, int>::type  n1; 
	enable_if<true>::type       n2; 
	enable_if<false, int>::type n3; 
}
