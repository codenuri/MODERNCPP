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

	auto [x4, y4, _] = p3d; // error. 이미 선언된 _ 변수를 다시한번 선언한것




	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "월요일";

	// map은 pair를 보관합니다.
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "화요일";
	m.insert(p);

}

