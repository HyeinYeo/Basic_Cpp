#include <iostream>
using namespace std;

/* 산술 연산자 오버로딩 */
/*
	<오버로딩>
	- 같은 이름의 메소드(method) 또는 생성자를 매개변수의 개수나 타입을 "다르게" 지정함으로써 2개 이상 정의하는 것
	
	< 연산자 오버로딩>
	1. 오버로딩 가능한 연산자
		- 산술 연산자
		- 입출력 연산자
		- 단항 연산자
		- 비교 연산자
		- 증감 연산자
		- 첨자 연산자
		- 괄호 연산자
		- 논리 연산자
		- 멤버 선택 연산자 
		- 형변환 연산자
		- 대입 연산자
		- 비트 연산자 
		- 포인터 관련 연산자
		- 메모리 연산자
		
	2. 오버로딩 불가 연산자
		- 조건 연산자(삼항연산자) ?:
		- 범위 지정 연산자 ::
		- 크기 연산자 sizeof
		- 멤버 선택 연산자 .
		- 포인터 이용 멤버 선택 연산자 .* 
	
	3. 멤버 함수로만 오버로딩해야 하는 연산자
		- 대입 연산자 =
		- 첨자 연산자 []
		- 괄호 연산자 ()
		- 멤버 선택 연산자 ->
		
	** 연산자 오버로딩 해도 우선순위는 그대로
	** 연산자 함수는 디폴트 매개변수 사용 불가능 
	
	<연산자 함수 작성 방법>
	리턴타입 operator 연산자(매개변수리스트); 
	
	1. 외부(전역) 함수로 구현하고, 클래스에 프렌드 함수로 선언
	2. 클래스의 멤버함수로 선언 
*/

// 1. 외부(전역) 함수로 구현하고, 클래스에 프렌드 함수로 선언
Color operator + (Color op1, Color op2);
bool operator == (Color op1, Color op2);

class Color{
	friend Color operator + (Color op1, Color op2);
	friend bool operator == (Color op1, Color op2);
};


// 2. 클래스의 멤버함수로 선언 
class Color{
	friend Color operator + (Color op2); // 왼쪽 피연산자는 자기 자신
	//  friend Color operator + (this, Color op2);와 같음. 
	friend bool operator == (Color op2);
};


