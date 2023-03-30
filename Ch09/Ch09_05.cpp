#include <iostream>
using namespace std;
/* ���� ������ �����ε� */
/*	
	<���� ������>
		++, --
		** ����, ���� ����!
	
	<���� ������ �����ε�>
		- ���� ���� ������
			- ���� 1��ŭ �����ϴ� �� �ٷ� �ݿ�
			- �ڱ� �ڽ��� ������ ����
			
			=> ++x�� l-value �� �� ����(���� ����) 
			
		- ���� ���� ������
			- ���� 1��ŭ �����ϴ� ���� ���� �ݷ��� ���� �Ŀ� �ݿ�
			- ���� ���� �����ڿ� �����ϱ� ���� dummy �Ű������� int ����
				- dummy -> �ƹ� ���ҵ� ���� ����, just ������ ����
			- ������ ����� �ٷ� �ݿ����� �ʱ� ������ �̸� ���� ���� ���� �Űܳ��� ������ ����
			- �׸��� "�ӽ� ������ �� ���� ���� ��"�� ����
			  => call by value Ÿ�� ���� 
			- ���� ��ų �� '����' ���� �����ڸ� �ʿ�� �ϹǷ� ���� ������ �����ε� �ʼ�
			
			=> x++�� l-value �� �� ����(���� ���� �Ұ���) 
			 
	1. ���� �Լ� ���� 
		- ���� �Լ��̹Ƿ� �ڿ� const�� ���� �� ����
		
	2. ��� �Լ� ���� 
		- ��� �Լ��� �����ϴ� �μ��� ���� �ʿ䰡 ���� (this�� �����Ǿ� ����) 
		- const ���̱� ���� 
		** ����) const�� ���� �� �ִ°� ��� �Լ��� ����
			- const ��ü�� ����� �� �ִ� ��� �Լ��� �� 
		
*/
class Digit
{
private:
	int m_digit;
public:
	Digit(int digit = 0) : m_digit(digit) {}

	friend ostream & operator << (ostream &out, const Digit &d)  // ���� �Լ�
	{
		out << d.m_digit;
		return out;
	}
	/* ���� ���� ������ */
	// ���� �Լ� ���� 
	friend Digit& operator ++ (Digit &digit) 
	{ 							// ���� �����־�� �ϴ� const�� ������ �ʾƾ� ��
								// ��ü ����� ������Ѿ� �ϹǷ� ������ �޾ƾ� �� 
		++digit.m_digit;
		return digit; // �ڱ� �ڽ��� "����"�� ����!! 
	}
	
	// ��� �Լ� ���� 
	Digit& operator ++ () 
	{
		++m_digit;
		return *this; // �ڱ� �ڽ�(DigitŸ�� ��ü)�� ����
	}
	
	/* ���� ���� ������ */
	// ���� �Լ� ����
	friend Digit operator ++ (Digit &digit, int){
		Digit temp(digit.m_digit);
		++digit; // �����ε� �� ���� ���� ������ ȣ�� 
		return temp; // call by value�� ����
	}
	
	// ����Լ� ����
	Digit operator ++ (int){
		Digit temp(m_digit);
		++*this; // �ڱ� �ڽ��� ���� ����, �����ε� �� ���� ���� ������ ȣ�� 
		return temp; // call by value�� ����
	} 
};


int main()
{
	Digit d(5);

	cout << ++d << endl;  // 6 ���
	cout << d << endl;  // 6 ���

	return 0;
}
