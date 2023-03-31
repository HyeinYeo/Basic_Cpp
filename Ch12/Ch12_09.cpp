#include <iostream>
using namespace std;
/* 객체 잘림, reference_wrapper */
/*	
	1. 객체 잘림
		- 부모에 자식을 구겨 넣을 때 발생
			메모리 크기: 자식 타입 객체 > 부모 타입 객체
		- 부모로부터 상속받은 부분만 들어감 
		- 다형성 X 
		
		<-> 부모 클래스형 포인터로 자식 객체 가리키는 것과 다름! => 다형성 O 
*/

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived : public Base
{
public:
	int m_j = 1;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

int main()
{
	Derived d;
	Base b = d; // 복사 -> 객체 잘림 발생

	b.print();  // I'm Base 출력
	// Derived만의 부분들은 잘려 버리고 Base로부터 상속받은 부분들만 b에 들어감
	// virtual 했음에도 다형성 사용 불가능 

	return 0;
}
