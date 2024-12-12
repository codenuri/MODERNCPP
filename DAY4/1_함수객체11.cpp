inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

template<typename T>
void foo(T f)
{
	bool b = f(1, 2); // A
}

int main()
{
	foo(cmp1);		// foo( bool(*)(int, int) ) 생성
	foo(cmp2);		// foo( bool(*)(int, int) ) 생성 => 위와 동일. f(1,2) 치환 안됨
	foo(Less{});	// foo( Less )			f(1,2) 치환
	foo(Greater{});	// foo( Greater )		f(1,2) 치환
}
// 위 코드를 보고 아래 물음에 답해 보세요
// 1. foo 함수는 몇개 생성되었을까요 ?		==> 3개
// 2. 각각의 foo 에서 A 부분의 인라인치환여부를 생각해 보세요
// 3. foo 를 제외한, 나머지 함수는 몇개 있을까요 ?
//	  main, 
//    cmp1, cmp2,  => 인라인치환으로만 사용되었다면 별도 함수가 생성될 필요는 없지만
//						호출의 용도로 사용되고 있으므로 함수가 생성되어야 한다.
//    Less::operator(), Greater::operator() => 치환의 용도만 사용되므로
//												별도의 함수로 생성안된다.
//												-Ob1 이 없다면 별도로 생성됨.

