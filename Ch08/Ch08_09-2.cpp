#include <iostream>
using namespace std;

/*	복사 생성자 */
/* 
	- 클래스는 모두 const이자 같은 타입의 객체를 참조로 
	  인수 1개를 받아 그 멤버들의 값을 내 멤버들에 복사하는 복사생성자를 디폴트로 가지고 있음
	  
	- 복사 생성자가 호출되는 경우
		- 먼저 생성한 객체를 나중에 생성한 객체의 생성자 인자로 전달할 때
		- 함수의 인자로 객체를 Call by Value 형태로 전달할 때
		- 객체를 Call by Value 형태로 리턴할 때 
 */
class Something
{
public:
	int m_value = 0;
	
	Something(const Something &st_in)  // 복사 생성자를 직접 정의
	{
		m_value = st_in.m_value;
		cout << "Copy constructor" << endl;
	}
	
	Something()
	{
		cout << "Constructor" << endl;
	}
    
	void setValue(int value) { m_value = value; }
	int getValue() const { return m_value; }
};

void print1(Something st) // Something st = something 이 실행될 때 클래스에 디폴트로 숨겨져 있던 복사 생성자가 호출
{
	cout << &st << endl; // &something과 주소값 다름 
	cout << st.getValue() << endl;
}

void print2(const Something & st) // 복사 생성자가 호출되지 않음(참조변수로 전달했으니 새로 생성 X) 
{
	cout << &st << endl;
	cout << st.m_value << endl;
}


int main()
{
	Something something;
	
	cout << &something << endl; // &st와 주소값 다름 

	print1(something);
	print2(something);

	return 0;
}
