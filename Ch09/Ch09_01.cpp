#include <iostream>
using namespace std;
/* ��� ������ �����ε� */
/*
	��� ������ �����ε�
		<����Ÿ��> operator ������ (�Ű�����)
		
		- �����ڿ� Ư�� Ÿ���� ��ü�� �ǿ����ڷ� ���� �� � �ൿ�� �ϰԲ� �̸� ����
*/

 
class Cents{
	int m_cents; 
	
public:
	Cents(int cents){
		m_cents = cents;
	} 
	int getter() const {
		return m_cents;
	}
	
	// ��� �Լ� �����ε�
	int operator + (const Cents &c1){
		return m_cents + c1.m_cents; // this->m_cents + c1.m_cents
	} 
	
	// ���� �Լ� �����ε� ��� �� �����Ϸ��� ����� private�� ��
	friend int operator + (const Cents &c1, const Cents &c2); 
};

// ���� �Լ� �����ε� 
int operator + (const Cents &c1, const Cents &c2){
		return c1.m_cents + c2.m_cents;
}

int main(){
	Cents c1(6);
	Cents c2(8);
	cout << c1.getter() + c2.getter() << endl;
	
	cout << c1 + c2 << endl;
	// c1.+(c2);�� ��ȯ�Ǿ� ���޵�
	// +�� �Լ����̶�� �����غ��� ex. c1.plus(c2); ������ ��! 
	
	return 0;
}
