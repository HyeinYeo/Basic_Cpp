#include <iostream>
using namespace std;
/* 단항 연산자 오버로딩 */
/*	
	<단항 연산자>
		+, -, !
		
	<단항 연산자 오버로딩>
		(friend) <리턴타입> operator 연산자 (매개변수) 
		
	1. 전역 함수 구현 
		- 전역 함수이므로 뒤에 const가 붙을 수 없음
		
	2. 멤버 함수 구현 
		- 멤버 함수로 구현하니 인수를 받을 필요가 없음 (this가 생략되어 있음) 
		- const 붙이기 가능 
		** 참고) const가 붙을 수 있는건 멤버 함수만 가능
			- const 객체가 사용할 수 있는 멤버 함수가 됨 
		
*/

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }

	friend std::ostream& operator << (std::ostream &out, const Cents &cents) // 출력 연산자 오버로딩 
	{
		out << cents.m_cents;
		return out;
		
	}
	
	/* 전역 함수로 구현 */ 
	// - 단항 연산자 오버로딩 
    friend Cents operator - (const Cents& c) // `-` 연산자 오버로딩 friend 지정
    {
	    return Cents(-c.m_cents);
    }
    
    // + 단항 연산자 오버로딩
    /*
	friend Cents operator + (const Cents &c){
		return Cents(c.m_cents < 0 ? (c.m_cents * -1) : c.m_cents);
	} */
	
	// ! 단항 연산자 오버로딩
	friend bool operator ! (const Cents &c){
		return (c.m_cents == 0 ? true : false);
	} 
	
	/* 멤버 함수로 구현 */ 
	// + 단항 연산자 오버로딩
	Cents operator + () const{ // 매개변수는 this이므로 생략 
		return Cents(m_cents < 0 ? (m_cents * -1) : m_cents);
	}
    
    
};


int main()
{	
	// - 단항 연산자 오버로딩
	Cents cents1(6);

	cout << cents1 << endl;   // 6 출력 
	cout << -cents1 << endl;  // -6 출력
	cout << -Cents(-10) << endl;  // 10 출력(익명 객체)
    cout << cents1 << endl;   // 6 출력 
    
    // + 단항 연산자 오버로딩
    Cents c2(-5);
    cout << c2 << endl; // -5
    cout << +c2 << endl; // 5
    
    // ! 단항 연산자 오버로딩
    Cents c3(0), c4(5);
    cout << !c3 << endl; // 1
    cout << !c4 << endl; // 0
    

	return 0;
}
