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
	foo(cmp1);
	foo(cmp2);
	foo(Less{});
	foo(Greater{});
}
// 위 코드를 보고 아래 물음에 답해 보세요
// 1. foo 함수는 몇개 생성되었을까요 ?
// 2. 각각의 foo 에서 A 부분의 인라인치환여부를 생각해 보세요
// 3. foo 를 제외한, 나머지 함수는 몇개 있을까요 ?
