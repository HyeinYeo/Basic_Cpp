#include <iostream>
using namespace std;
/*  형변환 오버로딩 */
/*	
	
	<형변환 오버로딩>
		- 특정 객체가 어떤 자료형으로 형변환 되야하는 시점에 호출
		  Cents c;
		  int(c); // 에러! => 형변환 오버로딩 사용
		- 형식
		 	operator 자료형이름()
		
		- **멤버 함수로만 구현 가능!!	 
		
*/
class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0)
	{
		m_cents = cents;
	}
	int getCents() { return m_cents; }
	void setCents(int cents) { m_cents = cents; }

	operator int()   // Cents 타입의 객체가 int 로 형변환 되어야 할 때 호출
	{
		cout << "cast here" << endl; 
		cout << m_cents << endl;
		return m_cents;
	}
};

// 달러를 센트로 자동 형변환하기 
class Dollar
{
private:
	int m_dollars = 0;

public:
	Dollar(const int &input) : m_dollars(input) {}

	operator Cents()  // Dollar 타입의 객체가 Cents 타입으로 형변환 되어야 할 때 호출
	{
		return Cents(m_dollars * 100); // 1 달러 == 100 센트 
	}
};


void printInt(const int &value)
{
	cout << value << endl;
}

int main()
{
	Cents cents(7);

	int value = (int)cents;   // 형변환 오버로딩 호출 
	value = int(cents);   // 형변환 오버로딩 호출 
	value = static_cast<int>(cents);   // 형변환 오버로딩 호출 
	printInt(cents);  // 형변환 오버로딩 호출 

	// 달러를 센트로 자동 형변환하기 
    Dollar dol(2);

    Cents cents = dol;  // 형변환 오버로딩 호출. m_dollars는 200이 됨 

	return 0;
}
