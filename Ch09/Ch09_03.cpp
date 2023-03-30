#include <iostream>
using namespace std;
/* ���� ������ �����ε� */
/*	
	<���� ������>
		+, -, !
		
	<���� ������ �����ε�>
		(friend) <����Ÿ��> operator ������ (�Ű�����) 
		
	1. ���� �Լ� ���� 
		- ���� �Լ��̹Ƿ� �ڿ� const�� ���� �� ����
		
	2. ��� �Լ� ���� 
		- ��� �Լ��� �����ϴ� �μ��� ���� �ʿ䰡 ���� (this�� �����Ǿ� ����) 
		- const ���̱� ���� 
		** ����) const�� ���� �� �ִ°� ��� �Լ��� ����
			- const ��ü�� ����� �� �ִ� ��� �Լ��� �� 
		
*/

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }

	friend std::ostream& operator << (std::ostream &out, const Cents &cents) // ��� ������ �����ε� 
	{
		out << cents.m_cents;
		return out;
		
	}
	
	/* ���� �Լ��� ���� */ 
	// - ���� ������ �����ε� 
    friend Cents operator - (const Cents& c) // `-` ������ �����ε� friend ����
    {
	    return Cents(-c.m_cents);
    }
    
    // + ���� ������ �����ε�
    /*
	friend Cents operator + (const Cents &c){
		return Cents(c.m_cents < 0 ? (c.m_cents * -1) : c.m_cents);
	} */
	
	// ! ���� ������ �����ε�
	friend bool operator ! (const Cents &c){
		return (c.m_cents == 0 ? true : false);
	} 
	
	/* ��� �Լ��� ���� */ 
	// + ���� ������ �����ε�
	Cents operator + () const{ // �Ű������� this�̹Ƿ� ���� 
		return Cents(m_cents < 0 ? (m_cents * -1) : m_cents);
	}
    
    
};


int main()
{	
	// - ���� ������ �����ε�
	Cents cents1(6);

	cout << cents1 << endl;   // 6 ��� 
	cout << -cents1 << endl;  // -6 ���
	cout << -Cents(-10) << endl;  // 10 ���(�͸� ��ü)
    cout << cents1 << endl;   // 6 ��� 
    
    // + ���� ������ �����ε�
    Cents c2(-5);
    cout << c2 << endl; // -5
    cout << +c2 << endl; // 5
    
    // ! ���� ������ �����ε�
    Cents c3(0), c4(5);
    cout << !c3 << endl; // 1
    cout << !c4 << endl; // 0
    

	return 0;
}
