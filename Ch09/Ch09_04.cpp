#include <iostream>
using namespace std;
/* 비교 연산자 오버로딩 */
/*	
	<비교 연산자>
		==, !=, >, >=
		
		== : 주소가 같냐, 즉 동일한 객체인가냐에 대한 결과를 얻음
			 -> 오버로딩?  어떤 멤버 변수 값이 같으면 같은 객체라고 하고 싶을 때 
		
	<단항 연산자 오버로딩>
		(friend) <리턴타입(bool)> operator 연산자 (매개변수) 
		- bool 타입을 리턴하도록 구현하는 것을 권장
		
		- <, <= 는 불가능!!!!
		
	1. 전역 함수 구현 
		- 전역 함수이므로 뒤에 const가 붙을 수 없음
		
	2. 멤버 함수 구현 
		- 멤버 함수로 구현하니 인수를 받을 필요가 없음 (this가 생략되어 있음) 
		- const 붙이기 가능 
		** 참고) const가 붙을 수 있는건 멤버 함수만 가능
			- const 객체가 사용할 수 있는 멤버 함수가 됨 
		
*/

#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend std::ostream& operator << (std::ostream &out, const Cents &cents)
	{
		out << cents.m_cents;
		return out;
	}
	
	// 전역함수 구현 
	friend bool operator == (const Cents &c1, const Cents &c2)
	{
		return c1.m_cents == c2.m_cents;
	}
	
	// 멤버함수 구현
	bool operator < (const Cents &c2)
	{
		return this->m_cents < c2.m_cents;
	}

	bool operator == (const Cents &c2)
	{
		return this->m_cents == c2.m_cents;
	} 
};

int main()
{
	Cents cents1(6);
	Cents cents2(6);

	if (cents1 == cents2)
		cout << "Equal " << endl;
	return 0;
}
