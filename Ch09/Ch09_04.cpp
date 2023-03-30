#include <iostream>
using namespace std;
/* �� ������ �����ε� */
/*	
	<�� ������>
		==, !=, >, >=
		
		== : �ּҰ� ����, �� ������ ��ü�ΰ��Ŀ� ���� ����� ����
			 -> �����ε�?  � ��� ���� ���� ������ ���� ��ü��� �ϰ� ���� �� 
		
	<���� ������ �����ε�>
		(friend) <����Ÿ��(bool)> operator ������ (�Ű�����) 
		- bool Ÿ���� �����ϵ��� �����ϴ� ���� ����
		
		- <, <= �� �Ұ���!!!!
		
	1. ���� �Լ� ���� 
		- ���� �Լ��̹Ƿ� �ڿ� const�� ���� �� ����
		
	2. ��� �Լ� ���� 
		- ��� �Լ��� �����ϴ� �μ��� ���� �ʿ䰡 ���� (this�� �����Ǿ� ����) 
		- const ���̱� ���� 
		** ����) const�� ���� �� �ִ°� ��� �Լ��� ����
			- const ��ü�� ����� �� �ִ� ��� �Լ��� �� 
		
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
	
	// �����Լ� ���� 
	friend bool operator == (const Cents &c1, const Cents &c2)
	{
		return c1.m_cents == c2.m_cents;
	}
	
	// ����Լ� ����
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
