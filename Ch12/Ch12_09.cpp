#include <iostream>
using namespace std;
/* ��ü �߸�, reference_wrapper */
/*	
	1. ��ü �߸�
		- �θ� �ڽ��� ���� ���� �� �߻�
			�޸� ũ��: �ڽ� Ÿ�� ��ü > �θ� Ÿ�� ��ü
		- �θ�κ��� ��ӹ��� �κи� �� 
		- ������ X 
		
		<-> �θ� Ŭ������ �����ͷ� �ڽ� ��ü ����Ű�� �Ͱ� �ٸ�! => ������ O 
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
	Base b = d; // ���� -> ��ü �߸� �߻�

	b.print();  // I'm Base ���
	// Derived���� �κе��� �߷� ������ Base�κ��� ��ӹ��� �κе鸸 b�� ��
	// virtual �������� ������ ��� �Ұ��� 

	return 0;
}
