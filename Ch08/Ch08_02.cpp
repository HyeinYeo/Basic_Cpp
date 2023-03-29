#include <iostream>
using namespace std;

/* ĸ��ȭ & ���� ������ & ���� �Լ� */

/*
	1. ĸ��ȭ
		- �ܺηκ��� �߿��� �����Ϳ� ����� ��ȣ�ϰ� ����
		- �����Ϳ� ��ɵ� �߿��� ������ �� �ִ� ������ �����ϰ� �ܺηκ��� �����ϴ� ��
		
		- ����
			-  Ŭ���� ���� ��� ���� �̸��� �ٲ�� �� ���� ����ٸ� 
			   �ش� ����� ���� �����Ͽ� ����� �κе鵵 �� �̸��� �ٲ���� ��
			-  ĸ��ȭ ��� �� ��� �������� �ٲ�� �� ���� �׳� Ŭ���� ���ο����� �ٲپ� �ָ� �� 
		
	2. ���� ������ 
		** ��� X -> �⺻�� private
		 
		- public : �ܺ��� ��� ������ ���� ���
		
		- private: Ŭ���� �� ��� �Լ��θ� ���� ����
			- �����Լ� setter / getter
				- public�� ���� �Լ����� ����� �̸� ���� ���������� ����
				
			- ���� �ٸ� ������ ��ü���� Ŭ���� Ÿ���� �����ϴٸ� �� ����� ������ private ��� ������ ���� ����
				- ���� �������� ���� ���� ������ Ŭ���� ����(�׶� �׶� ������ �ν��Ͻ��� ������ �ƴ�)
		
		- protected: Ŭ���� �� ��� �Լ� + ��� �޴� �ڽ� Ŭ������ ��� �Լ� ���� ���� 
		
*/

class Date
{
	int m_year; // private, �ܺο��� ���� ���� ������ �� ����
	int m_month;
	int m_day;
	
public:
	int x; // �ܺο��� �� ���� ���� 
	
	// ���� �Լ� 
	void setter(const int &year_input, const int &month_input, const int &day_input){
		m_year = year_input;
		m_month = month_input;
		m_day = day_input;
	}
	
	const int& getterYear() {
		return m_year;
	}
	
	// Ŭ���� Ÿ���� �����ϴٸ� �� ����� ������ private ��� ������ ���� ����
	void copyFrom(const Date& origin){
		m_year = origin.m_year;
		m_month = origin.m_month;
		m_day = origin.m_day;
	} 
	
};

int main(){
	Date today; 
	today.setter(2022, 8, 15);
	cout << today.getterYear() << endl;  // 2022 ���, m_year ����� ���� �޴´�.
	
	Date original;
	original.setter(2002, 4, 1);
	today.copyFrom(original);
	cout << today.getterYear() << endl; // 2002 ��� 

	return 0;
}
