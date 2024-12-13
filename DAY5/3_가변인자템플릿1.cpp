// 가변인자템플릿1 - 225 page

// 가변인자 클래스 템플릿
//template<typename T> class tuple // tuple 사용시 타입을 한개만 전달해야 합니다.
template<typename ... Types> class tuple // 타입을 몇개라도 전달 가능합니다.
{										 // "Types" 안에는 여러개 타입이 있습니다.
										 // 그래서, 관례적으로 복수형태의 이름사용
};

int main()
{
	tuple<> t0;
	tuple<int> t1;
	tuple<int, char> t2;
	tuple<int, double, char> t3;
}
