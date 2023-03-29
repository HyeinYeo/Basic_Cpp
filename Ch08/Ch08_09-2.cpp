#include <iostream>
using namespace std;

/*	���� ������ */
/* 
	- Ŭ������ ��� const���� ���� Ÿ���� ��ü�� ������ 
	  �μ� 1���� �޾� �� ������� ���� �� ����鿡 �����ϴ� ��������ڸ� ����Ʈ�� ������ ����
	  
	- ���� �����ڰ� ȣ��Ǵ� ���
		- ���� ������ ��ü�� ���߿� ������ ��ü�� ������ ���ڷ� ������ ��
		- �Լ��� ���ڷ� ��ü�� Call by Value ���·� ������ ��
		- ��ü�� Call by Value ���·� ������ �� 
 */
class Something
{
public:
	int m_value = 0;
	
	Something(const Something &st_in)  // ���� �����ڸ� ���� ����
	{
		m_value = st_in.m_value;
		cout << "Copy constructor" << endl;
	}
	
	Something()
	{
		cout << "Constructor" << endl;
	}
    
	void setValue(int value) { m_value = value; }
	int getValue() const { return m_value; }
};

void print1(Something st) // Something st = something �� ����� �� Ŭ������ ����Ʈ�� ������ �ִ� ���� �����ڰ� ȣ��
{
	cout << &st << endl; // &something�� �ּҰ� �ٸ� 
	cout << st.getValue() << endl;
}

void print2(const Something & st) // ���� �����ڰ� ȣ����� ����(���������� ���������� ���� ���� X) 
{
	cout << &st << endl;
	cout << st.m_value << endl;
}


int main()
{
	Something something;
	
	cout << &something << endl; // &st�� �ּҰ� �ٸ� 

	print1(something);
	print2(something);

	return 0;
}
