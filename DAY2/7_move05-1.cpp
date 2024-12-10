// 7_move05-1.cpp

int main()
{
	// java, C#, python 
	// => 객체를 힙에 만들고 포인터(reference) 로 관리하는 언어.
	// => move 개념이 없고, clone 개념이 있습니다]
	// => 아래 코드를 C#, Java 라고 가정
	// => C#, Java 는 Cat 가 적어도 "Cat*" 의미.

	Cat c1 = new Cat("yaong", 3);
	Cat c2 = c1;	// 복사도 아니고, 이동도 아닌, 객체 공유의 개념
	Cat c3 = c1.Clone();

	// 위방식대로 동작하는 언어는 
	// => move 개념이 거의 필요 없습니다
	// 하지만
	// => 객체의 삭제에 대한 해결책이 있어야 합니다
	// => 객체가 공유 되므로 "참조계수"도 관리 되어야 합니다.
	// => 결국, 각 언어가 책임져야 합니다.(C++은 사용자가 해야 해서 복잡합니다)
	// => 멀티 스레드 환경에서 동기화가 필요 합니다.
	// ----------------------------------------------

	// C++ : 모든 것을 할수 있는 자유로운 언어 입니다

	// Java, C# 스타일로 하려면
	Cat* c1 = new Cat("yaong", 2);
	Cat* c2 = c1;
	// => delete 책임이 필요 합니다

	// C++ : 값 기반 언어, stack 에 만들지 힙에 만들지 결정 가능
	// => 아래 코드는 stack 에 만들어서 사용하는 코드
	std::string s1 = "hello";
	std::string s2 = s1; 

	
	// 일반적으로 move 는 빠르고, copy 는 느립니다.
	// C++ : 예전에는 move 없었음. 
	std::string s2 = s1;			// copy.   느린 방식이 디폴트
	std::string s3 = std::move(s1);	// move.   빠른 방식이 선택

	// RUST : 대부분의 개념이 C++의 반대
	s2: String = s1;		// move 로 동작, 다음줄에서 s1 은 자원이 없음.
	s3: String = s1.Clone();// copy 로 동작, 다음중에서 s2 는 자원 있음. 
}