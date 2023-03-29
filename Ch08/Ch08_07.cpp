#include <iostream>
using namespace std;

/*	this������ & ���� ȣ�� */
/* 
	- this
		- �ڱ� �ڽ�(��ü)�� �ּҸ� ��� ������ 
		- this -> ����� ����
			- cf. python�� self 
		- Ŭ���� ������ ������� ����� �� �տ� �� this->�� �ٴµ� �����Ǵ� ���� �� 
	
	- ���� ȣ�� 
		- �ڱ� �ڽ�(��ü)�� ����
 */

class Simple
{
private:
	int m_id;

public: 
	Simple(int id)
	{
        
        setID(id);  // this->setID(id)�� ���� 
        
        cout << m_id << endl; // cout << this->m_id << endl �� ���� 

        cout << this << endl; // ��ü �ڱ� �ڽ��� �ּҰ��� ��� 
	}
	void setID(int id) { m_id = id; }
	int getID() { return m_id; }
};

// ����ȣ��
class Calc
{
private:
	int m_value;

public: 
	Calc(int init_value)     //������
		: m_value(init_value)
	{}
	Calc& add(int value) { m_value += value; return *this;} // �ڱ� �ڽ��� ���� 
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this;}
	void print() { cout << m_value << endl; }
}; 

int main()
{
    Simple s1(1);  // 1,  0x6ffe10 ���
    Simple s2(2);  // 2,  0x6ffe00 ���

    cout << &s1 << " " << &s2 << endl;  // 0x6ffe10 0x6ffe00 ���
	
	
	// ���� ȣ��
	Calc cal(10);
	cal.add(10).sub(1).mult(2).print(); 
    return 0;
}
