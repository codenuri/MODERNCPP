// 20_타입추론1 - 69 page
// 타입 추론 문법

template<typename T>
void foo(T a)
{

}

int main()
{
	auto n = 3;		// int n = 3;  auto 는 우변으로 타입 추론
	decltype(n) d;	// int d;      decltype 은 () 안에 있는 표현식의 타입 추론
	foo(3);			// 템플릿은 함수 인자를 보고 T 를 추론. 
}

// type deduction(type inference, 타입추론, 타입 연역)
// => 주어진 표현식을 가지고 컴파일러가 타입을 
//    결정하는것

// 1. template
// 2. auto
// 3. decltype

// 1, 2 는 동일한 규칙 사용 => template 으로 학습하는 것이 확인하기 좋습니다.
// => 그래서 template 으로 학습후,
// => 동일한 규칙을 auto 에 적용하면 됩니다.
// 
// 3 은 다른 규칙 사용.

