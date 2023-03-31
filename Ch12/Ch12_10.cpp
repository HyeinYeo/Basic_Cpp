#include <iostream>
using namespace std;
/* 동적 형변환 */
/*	
	- dynamic_cast : 동적으로 형변환
		- 형변환에 실패할 경우 nullptr 리턴
		
		dynamic_cast<바꿀타입*>(바뀔객체);
	
	- static_cast
		- static_cast는 되는대로 밀어붙임 
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

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "I'm derived_1" << endl;
	}
};

class Derived2 : public Base
{
public:
	string m_name = "Dr. Two";

	virtual void print() override
	{
		cout << "I'm derived_2" << endl;
	}
};

int main()
{
	Derived1 d1;
	Base *base = &d1;

	auto *base_to_d1 = dynamic_cast<Derived1*>(base); // 동적 형변환
	//  Derived2로는 형변환 불가능 
	cout << base_to_d1->m_j << endl;

	return 0;
}
