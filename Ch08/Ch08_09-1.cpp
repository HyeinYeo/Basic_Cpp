#include <iostream>
using namespace std;

/*	Ŭ������ const */
/* 
	- const <Ŭ������> ��ü
		- '��ü�� ����� ���� �ٲ� �� ����'
		- setter ���� �Լ� ��� �Ұ���
			- setter�� const ��� �Լ��� ���� �� ���� 
		- getter ���� �Լ��� ��뵵 �Ұ���
		- �ڿ� const�� ���� ��� �Լ��� ��� ����
			- ��� �Լ��� const�ΰ� �ƴѰ��� �Ǵ�
		- �Լ��� �μ��� ��ü�� �ѱ� ��, �� �ȿ��� ���� ���� �ִ� ��� �Լ���� �ڿ� const�� �ٿ��־�� �� 
		- const�� ���� ���� �Ϲ� ��ü�� const��� �Լ��� ȣ���� �� ���� 
 */
 
class Something{
	int m_value;
	
public:
	Something(){
		m_value = 0;
	}
	void setter(int value){
		m_value = value;
	}
	int getter() const{ // �Լ� �ڿ� const ���̸� ��������� �������� ���ϰ� read-only�� ����ڴٴ� �� 
		return m_value;
	}
 };
 
 
 int main(){
 	const Something s1;
 	Something s2;
 	
 	//s1.setter(1); // �Ұ���
	s2.setter(2); // ����
	
	cout << s1.getter() << endl; // ����
	cout << s2.getter() << endl; // ���� 
 } 
