struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

// forwarding reference 의 의미!!

// lvalue 와 rvalue 를 모두 받을수 있는 함수 만들기

// 방법 #1. call by value
// 특징 : 복사본이 생성됩니다.
// void foo(Point pt) {}

// 방법 #2. call by const lvalue reference
// 특징 1. 복사본 없이 lvalue, rvalue 모두 받을수 있다.
// 특징 2. 상수성이 추가된다. 원본 객체의 특성을 그대로 받는 것은 아니다.
void foo(const Point& pt) {}

// C++98 시절에는 위 2개 방법밖에 없습니다.
// => 인자의 원본을 변화 없이 그대로 lvalue, rvalue 모두 받는 방법은 없습니다.
//--------------------------------------------------------
// C++11 이후 가능한 2개의 기술

// 방법 #3. 2개의 함수(lvalue, rvalue 버전을 따로 제공)
// => 복사본도 없고, 상수성(const)도 추가되지 않는다.
void foo(Point& pt)  {}
void foo(Point&& pt) {}


// 방법 #4. forwarding reference(T&&) 를 사용하면 위 2개 함수를 
//          자동 생성 할수 있습니다.
//			=> 하는 일이 동일하면 사용자가 직접 2개 만들필요없이 자동생성하면됩니다.
//			=> 또한, Point 타입뿐 아니라 임의의 타입에 대해서 위 2개 함수 자동생성
//			=> Point&, Point&& 뿐 아니라 const Point& 등도 자동생성
template<typename T>
void foo(T&& pt)
{

}


int main()
{
	Point pt(0, 0);

	// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
	foo( pt );
	foo( Point(0,0) );
}
