#include <iostream>
using namespace std;
/* 증감 연산자 오버로딩 */
/*	
	<증감 연산자>
		++, --
		** 전위, 후위 구분!
	
	<증감 연산자 오버로딩>
		- 전위 증감 연산자
			- 값이 1만큼 증감하는 것 바로 반영
			- 자기 자신을 참조로 리턴
			
			=> ++x는 l-value 될 수 있음(참조 리턴) 
			
		- 후위 증감 연산자
			- 값이 1만큼 증감하는 것이 세미 콜론을 만난 후에 반영
			- 전위 증감 연산자와 구분하기 위해 dummy 매개변수인 int 설정
				- dummy -> 아무 역할도 하지 않음, just 구분을 위함
			- 연산의 결과가 바로 반영되지 않기 때문에 미리 연산 전의 값을 옮겨놓은 다음에 연산
			- 그리고 "임시 저장해 둔 연산 전의 값"을 리턴
			  => call by value 타입 리턴 
			- 증가 시킬 때 '전위' 증감 연산자를 필요로 하므로 전위 연산자 오버로딩 필수
			
			=> x++는 l-value 될 수 없음(참조 리턴 불가능) 
			 
	1. 전역 함수 구현 
		- 전역 함수이므로 뒤에 const가 붙을 수 없음
		
	2. 멤버 함수 구현 
		- 멤버 함수로 구현하니 인수를 받을 필요가 없음 (this가 생략되어 있음) 
		- const 붙이기 가능 
		** 참고) const가 붙을 수 있는건 멤버 함수만 가능
			- const 객체가 사용할 수 있는 멤버 함수가 됨 
		
*/
class Digit
{
private:
	int m_digit;
public:
	Digit(int digit = 0) : m_digit(digit) {}

	friend ostream & operator << (ostream &out, const Digit &d)  // 전역 함수
	{
		out << d.m_digit;
		return out;
	}
	/* 전위 증감 연산자 */
	// 전역 함수 구현 
	friend Digit& operator ++ (Digit &digit) 
	{ 							// 증가 시켜주어야 하니 const는 붙이지 않아야 함
								// 객체 멤버값 변경시켜야 하므로 참조로 받아야 함 
		++digit.m_digit;
		return digit; // 자기 자신을 "참조"로 리턴!! 
	}
	
	// 멤버 함수 구현 
	Digit& operator ++ () 
	{
		++m_digit;
		return *this; // 자기 자신(Digit타입 객체)을 리턴
	}
	
	/* 후위 증감 연산자 */
	// 전역 함수 구현
	friend Digit operator ++ (Digit &digit, int){
		Digit temp(digit.m_digit);
		++digit; // 오버로딩 된 전위 증감 연산자 호출 
		return temp; // call by value로 리턴
	}
	
	// 멤버함수 구현
	Digit operator ++ (int){
		Digit temp(m_digit);
		++*this; // 자기 자신을 증가 연산, 오버로딩 된 전위 증감 연산자 호출 
		return temp; // call by value로 리턴
	} 
};


int main()
{
	Digit d(5);

	cout << ++d << endl;  // 6 출력
	cout << d << endl;  // 6 출력

	return 0;
}
