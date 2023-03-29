#include <iostream>
using namespace std;

/*	this포인터 & 연쇄 호출 */
/* 
	- this
		- 자기 자신(객체)의 주소를 담는 포인터 
		- this -> 멤버로 접근
			- cf. python의 self 
		- 클래스 내에서 멤버들을 사용할 때 앞에 다 this->가 붙는데 생략되는 것일 뿐 
	
	- 연쇄 호출 
		- 자기 자신(객체)를 리턴
 */

class Simple
{
private:
	int m_id;

public: 
	Simple(int id)
	{
        
        setID(id);  // this->setID(id)와 같음 
        
        cout << m_id << endl; // cout << this->m_id << endl 와 같음 

        cout << this << endl; // 객체 자기 자신의 주소값을 출력 
	}
	void setID(int id) { m_id = id; }
	int getID() { return m_id; }
};

// 연쇄호출
class Calc
{
private:
	int m_value;

public: 
	Calc(int init_value)     //생성자
		: m_value(init_value)
	{}
	Calc& add(int value) { m_value += value; return *this;} // 자기 자신을 리턴 
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this;}
	void print() { cout << m_value << endl; }
}; 

int main()
{
    Simple s1(1);  // 1,  0x6ffe10 출력
    Simple s2(2);  // 2,  0x6ffe00 출력

    cout << &s1 << " " << &s2 << endl;  // 0x6ffe10 0x6ffe00 출력
	
	
	// 연쇄 호출
	Calc cal(10);
	cal.add(10).sub(1).mult(2).print(); 
    return 0;
}
