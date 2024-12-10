#include <iostream>""

// 반환 타입을 사용자가 정확히 표기 한것
// => C++11 부터 가능
// => return 문장이 여러개 있어도 가능, 결국 리턴 타입은 "decltype(a* b)" 이므로
// => decltype 규칙을 사용하므로 decltype(a*b) 가 참조로 결정되면 
//    반환 타입도 참조(아래 코드는 값 타입)
template<typename T1, typename T2>
auto  Mul1(T1 a, T2 b) -> decltype(a* b) 
{
	if (a == 0) return 0;
	return a * b;
}

// 컴파일러에게 리턴 문장을 보고 반환 타입을 추론해 달라고 한것
// => C++14 부터 가능
// => return 문장이 2개 이상이면 error. 
// => 아래 코드는 auto 규칙 사용
//    "auto a = return문장" 형태 인데,
//     auto 규칙 이므로 "return문장" 의 결과가 reference 라도, 반환 타입은 값 타입. 
template<typename T1, typename T2>
auto  Mul2(T1 a, T2 b)
{
	if (a == 0) return 0;

	return a * b;
}

// 결국, return 문장이 한개인 Mul, Add, Sub등을 만들때는
// => auto 만 표기해도 됩니다. (C++14 이상)
// => 함수구현이 복잡해서 2개이상의 return 문이 있거나
//    "return 표현식"이 참조일때 반환타입도 참조로 하고 싶다면 decltype() 사용


int main()
{
	std::cout << Mul1(3, 4.1) << std::endl;
	std::cout << Mul2(3, 4.1) << std::endl;

}

