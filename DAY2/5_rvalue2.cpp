// 핵심 : rvalue, lvalue 의 개념은 
//       변수(객체)에 부여되는 개념이 아닌
//       표현식(expression) 에 부여 되는 개념
// 
// statement(문장) : 세미 콜론으로 끝나는 한줄의 코드 ( 실행단위 )
// 
// expression(표현식) : 한개의 값을 만들어내는 코드의 집합
// 
// 표현식에 의해서 생성된 한개의 값은 2가지 속성이 있습니다.
// => 1. 타입 
// => 2. value category : lvalue, rvalue ( xvalue, prvalue )

int main()
{
	int n = 2;

	n * 2 + 3;	// 최종 값   : 7
				// 값의 타입 : int
				// value category : rvalue
				//			=> 사용자가 할당한 메모리에 있는 값이 아닌
				//			=> 연산의 과정에서 임시로 만들어진 값
				//				(CPU 의 레지스터 등에 잠시 보관된 것)
				//			다음줄이 실행될때 레지스터를 overwrite 하므로
				//			더이상 접근할수 없다.

}
