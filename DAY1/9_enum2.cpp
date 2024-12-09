
// C/C++98 시절의 enum 
// enum COLOR { red = 0, green = 1, blue = 2 };


// C++11 에서 새로나오는 enum 문법 
enum class COLOR { red = 0, green = 1, blue = 2 };


int main()
{
//	int n1 = red;			// error. COLOR 라는 이름 필요
//	int n2 = COLOR::red;	// error. int 타입이 아닌 COLOR 타입
							//        int 타입으로 암시적 변환 안됨
	COLOR c1 = COLOR::red;  // ok
	COLOR c2 = red;			// error. COLOR 필요
}





