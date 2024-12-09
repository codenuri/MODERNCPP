#include <list>

// 클래스 만들때
// => 멤버 데이타가 있다면, 생성자를 만들어서 초기화 하는 것이 관례 입니다.
// => 그런데, 멤버 데이타가 없다면 생성자도 필요 없을때가 많습니다.

class MyList : public std::list<int>
{
public:
	void print() {}

	// 아래 Main 을 되게 하려면
	// #1. C++98 시절이라면, 모든 형태의 생성자를 제공해야 합니다.
//	MyList(int sz, int v) : std::list<int>(sz, v) {}
//	MyList(int sz)        : std::list<int>(sz) {}

	// #2. C++11~ 이라면 생성자 상속 한번으로 해결 됩니다.
	using std::list<int>::list;  // std::list<int> : 타입(클래스) 이름
								 // list : 함수(생성자)이름 
};

int main()
{
	// MyList 를 std::list<int> 와 동일하게 사용할수 있어야 합니다.
	// => 그런데, 생성자 상속을 사용하지 않으면 아래 코드는 모두 에러 입니다.

	MyList st1(10, 3); // 10개를 3으로 초기화
	MyList st2(10);
}




