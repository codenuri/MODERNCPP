// 19_structure_binding - 52 page
#include <map>
#include <string>

struct Point3D
{
	int x = 0, y = 0, z = 0;
};
int main()
{
	Point3D p3d;

	// p3d 의 모든 멤버를 꺼내고 싶다.. util C++14
	int x1 = p3d.x;
	int y1 = p3d.y;
	int z1 = p3d.z;

	// C++17 부터는 아래 처럼 사용가능합니다.(python 과 유사)
	// => "structure binding" 이라는 문법
	auto [x2, y2, z2] = p3d; // 이 한줄은 위 3줄과 동일합니다.
							// auto x2 = p3d.x;
							// auto y2 = p3d.y;
							// auto z2 = p3d.z;
	
//	int[x3, y3, z3] = p3d; // error. auto 만 가능합니다.


//	auto [x3, y3] = p3d; // error. 갯수 맞아야 합니다
	

	auto [x3, y3, _] = p3d; // ok.  주의할 점은 _ 도 변수 이름이라는 것

//	auto [x4, y4, _] = p3d; // error. 이미 선언된 _ 변수를 다시한번 선언한것
							// 단, C++26 부터는 에러 아님. 
				
	// C++26 부터, 재미있는 문법한개가 추가되었습니다.
	// 이름이 _ 인 지역변수는 여러번 선언될수 있다.
//	int _ = 10;
//	int _ = 20; // C++26 부터 에러 아님.

	// 구조체 뿐 아니라 배열도 가능합니다.
	int arr[3] = { 1,2,3 };

	auto [a, b, c] = arr; // 갯수 맞아야 합니다.




	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "월요일";

	// map은 pair를 보관합니다.
	// 위 한줄은 결국 아래 4줄과 같은 코드 입니다.
	std::pair<std::string, std::string> p;

	p.first = "tue";
	p.second = "화요일";
	m.insert(p);

	// 핵심 map 의 모든 요소를 "range-for"로 열거 하는 방법
	// C++17 이전
	for (auto p : m)
	{
		// 여기서 p 는 std::pair 입니다.
		std::string key = p.first;
		std::string value = p.second;
	}


	// C++17 부터는 위 structure binding 을 사용하면 편리합니다.
	// => 아래 코드가 위코드와 동일합니다.
	for (auto[key, value] : m)
	{
		
	}
}

