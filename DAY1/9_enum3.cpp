
// C++98 enum : 내부적으로 각 요소의 타입을 int 로 관리 합니다. 변경할수 없습니다.
// C++11 enum : 요소의 타입을 지정할수 있습니다.

//enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 }; // 각 요소는 int
enum class DAYOFWEEK : char { SUN = 0, MON = 1, TUE = 2 }; // 각 요소를 char로 해달라

int main()
{
}




