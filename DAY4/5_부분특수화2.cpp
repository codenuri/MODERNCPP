#include <iostream>


// 160 page

// primary template 
template<typename T, typename U> struct Object
{
	static void foo() { std::cout << "T, U" << std::endl; }
};

template<typename T, typename U> struct Object<T*, U*>
{
	static void foo() { std::cout << "T*, U*" << std::endl; }
};

template<typename T, typename U> struct Object<T*, U>
{
	static void foo() { std::cout << "T*, U" << std::endl; }
};

// 핵심 : primary template 의 인자가 2개일때 
//		 template<typename T, typename U> struct Object

// #1. 사용자가 Object 사용시 반드시 2개의 인자를 전달해야 합니다. Object<int, int>
// #2. 부분 특수화 할때 오른쪽 끝(A 부분)에도 2개 표기해야 합니다.
// #3. 하지만 템플릿 인자의 갯수는 다를수 도 있습니다
//     아래 코드는 한개!

template<typename T> struct Object<T, T> // <==A
{
	static void foo() { std::cout << "T, T" << std::endl; }
};

// partial specilization 이 아닌 "specialization". 모든 타입이 확정된경우.
template<> struct Object<int, short>
{
	static void foo() { std::cout << "int, short" << std::endl; }
};

template<typename T, typename U, typename V > struct Object< T, Object<U, V> >
{
	static void foo() { std::cout << "T, Object<U, V>" << std::endl; }
};

int main()
{
	// 아래 처럼 나오게 만들어 보세요.
	Object<int,  double >::foo();// T, U
	Object<int*, double*>::foo();// T*, U*
	Object<int*, double> ::foo();// T*, U
	Object<int,  int>::foo();    // T, T
	Object<int, short>::foo();   // int, short

	// 위 내용을 보고 아래 결과가 나오도록 부분특수화 추가해 보세요
	Object<double, Object<short, char>>::foo();
						// "T, Object<U, V>" 로 출력되게 해보세요
	
}
using PINT = int*; // 컴파일러는 PINT 를 int* 로 인식
