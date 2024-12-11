// 2_forwarding_reference4-1.cpp
// 정리

// 함수 인자로 사용되는 레퍼런스의 의미

fn(int&) : int 타입 lvalue 만 받을수 있다.
fn(int&&) : int 타입 rvalue 만 받을수 있다.
fn(T&) : 임의 타입 lvalue 만 받을수 있다. (해당 타입의 lvalue& 함수를 생성)

fn(T&&) : 임의 타입 lvalue, rvalue 를 모두 받을수 있다.
		  => 한개 함수에서 모두 받는 것이 아니라, 템플릿 이므로
		  => 받을수있는 함수를 생성하겠다는 것. 
		  => 생성된 함수는 모두 call by value 가 아닌 call by reference
			 fn(int&) 또는 fn(int&&)

// 아래 내용 외워 두세요. 시험에 나옵니다.
template<typename T> fn(T&& arg) {} 에서

int n = 3;
fn(n), lvalue 전달 : T = int&, T&&=int& && => int&   fn(int&)   함수 생성
fn(3), rvalue 전달 : T = int,  T&&=int&&             fn(int&&)  함수 생성


// 