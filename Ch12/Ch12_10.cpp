#include <iostream>
using namespace std;
/* ���� ����ȯ */
/*	
	- dynamic_cast : �������� ����ȯ
		- ����ȯ�� ������ ��� nullptr ����
		
		dynamic_cast<�ٲ�Ÿ��*>(�ٲ�ü);
	
	- static_cast
		- static_cast�� �Ǵ´�� �о���� 
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

	auto *base_to_d1 = dynamic_cast<Derived1*>(base); // ���� ����ȯ
	//  Derived2�δ� ����ȯ �Ұ��� 
	cout << base_to_d1->m_j << endl;

	return 0;
}
