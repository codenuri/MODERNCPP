// 17_static_if - 51 page

// 아래 코드는 에러 일까요 ? 아닐까요 ?

// if : 실행시간 제어문, 조건식의 결과를 컴파일 시간에 알수 있어도
//		해당 구문은 템플릿 인스턴스화(실제 함수)에  포함됩니다.

// if constexpr : 컴파일 시간 제어문, 조건식의 결과는 반드시 컴파일 할때 알수 있어야 합니다.
//			      조건식이 false 라면 "템플릿 인스턴스화(실제 함수)"에 포함되지 않습니다.	  

template<typename T> void foo(T a)
{
//	if (false)
	if constexpr (false)
		*a = 10;
}

int main()
{
	foo(0); 
}

// 라이브러리 설계 자들은 아래 처럼 사용합니다
template<typename T>
void 중요한알고리즘(T a)
{
	if constexpr (std::is_pointer_v<T>)
	{
		// a가 포인터 일때 포인터에 최적화된 알고리즘
	}
	else if constexpr (std::is_class_v<T>)
	{
		// a가 class 일때 class에 최적화된 알고리즘
	}
	else if constexpr (std::is_floating_point_v<T>)
	{
		// a가 실수 일때 실수에 최적화된 알고리즘
	}
}

