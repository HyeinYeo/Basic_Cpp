#include <iostream>
using namespace std;
/*  ����ȯ �����ε� */
/*	
	
	<����ȯ �����ε�>
		- Ư�� ��ü�� � �ڷ������� ����ȯ �Ǿ��ϴ� ������ ȣ��
		  Cents c;
		  int(c); // ����! => ����ȯ �����ε� ���
		- ����
		 	operator �ڷ����̸�()
		
		- **��� �Լ��θ� ���� ����!!	 
		
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

	operator int()   // Cents Ÿ���� ��ü�� int �� ����ȯ �Ǿ�� �� �� ȣ��
	{
		cout << "cast here" << endl; 
		cout << m_cents << endl;
		return m_cents;
	}
};

// �޷��� ��Ʈ�� �ڵ� ����ȯ�ϱ� 
class Dollar
{
private:
	int m_dollars = 0;

public:
	Dollar(const int &input) : m_dollars(input) {}

	operator Cents()  // Dollar Ÿ���� ��ü�� Cents Ÿ������ ����ȯ �Ǿ�� �� �� ȣ��
	{
		return Cents(m_dollars * 100); // 1 �޷� == 100 ��Ʈ 
	}
};


void printInt(const int &value)
{
	cout << value << endl;
}

int main()
{
	Cents cents(7);

	int value = (int)cents;   // ����ȯ �����ε� ȣ�� 
	value = int(cents);   // ����ȯ �����ε� ȣ�� 
	value = static_cast<int>(cents);   // ����ȯ �����ε� ȣ�� 
	printInt(cents);  // ����ȯ �����ε� ȣ�� 

	// �޷��� ��Ʈ�� �ڵ� ����ȯ�ϱ� 
    Dollar dol(2);

    Cents cents = dol;  // ����ȯ �����ε� ȣ��. m_dollars�� 200�� �� 

	return 0;
}
