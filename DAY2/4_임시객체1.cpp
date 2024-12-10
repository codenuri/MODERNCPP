// 1_임시객체1 - 77 page
#include <iostream>

// 임시객체(temporary)
// => C++11 의 신기술은 아니고, C++98 시절부터 있던 개념
// => move 등의 기술을 이해하기 위해 반드시 알아야 되는 개념. 
// => PYTHON, RUST, C#, Java 등에도 있지만, 대부분의 개발자가 잘모르고 있습니다.

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};

int main()
{
//	Point pt(1, 2); // named object
					// 이름이 있으므로 아래 줄에서도 이름(pt)를 사용해서 접근 가능
					// 수명 : 자신을 선언한 {}을 벗어날때 파괴

//	Point (1, 2);	// unnamed object
					// 이름이 없으므로 아래 줄에서는 접근할수 없습니다.
					// 수명 : 자신을 선언한 문장의 끝(;)에서 파괴 
					// "temporary(임시객체)" 라고도 합니다.

	// 아래 코드 실행결과(화면출력) 예측해 보세요
	Point(1, 2), std::cout << "X\n";

	std::cout << "-------" << std::endl;
}





