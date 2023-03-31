#include <iostream>
#include <string>
using namespace std;
/* ������ Ŭ����(Derived class) ���� ���� */
/*
	1. �θ�κ��� ��� ���� �� ������ �ڱ� �ڽ��� ��
		- �θ�κ��� ��� ���� ������� �ڱ� �ڽ��� ������� ��
			m_i
			this -> m_i
			Mother::m_i = 1024
			this -> Mother::m_i = 1024
		- ��, Mother::����Լ�() => �������̵� �ڽ��Լ� X, �θ��Լ���
		
	2. �θ� �����ڴ� �ڽ� �����ں��� ������ ���� ȣ��
		- ������ �θ� ������ ���� ȣ�� 
		- A (�ҸӴ�) >> B(����) >> C(�ڽ�) ������ ��� ��,
		  A ������ >> B ������ >> C ������ �� ȣ�� 
		
		- �ܼ��� �޸𸮸� �Ҵ��ϴ� �Ͱ� �ʱ�ȭ�ϴ� �� ����
			- �޸� �Ҵ縸: �����Ⱚ �������
			- �ʱ�ȭ: �Ҵ� ���� �޸� ������ ���ϴ� ���� �� 
		- �޸𸮴� �ڽ��� ���� �Ҵ���� ���� ������, �ʱ�ȭ������ŭ�� ������ �θ� ������� ���� �ʱ�ȭ
*/
class Mother
{
public:
    int m_i;
    
    Mother()
        : m_i(0)
    {
        cout << "Mother construction" << endl;
	}
    
};


class Child : public Mother
{
public:
	double m_d;
	
    Child()
    	: Mother(), m_d(1.0) // Mother()�� ���� �տ� �����ִ� ��! => �׻� ���� ���� 
    {
    	cout << "Child construction" << endl;
    	
    	// 1. �θ�κ��� ��� ���� ������� �ڱ� �ڽ��� ���
    	// ** Mother���� m_i�� public�̱� ������ �̷��� ����
		m_i = 0;
		Mother::m_i = 5; 
        this -> m_i = 10;
        this -> Mother::m_i = 1024;
        
        cout << this -> m_i << endl;
		cout << this -> Mother::m_i << endl; 
    }
};

int main(){
	// 2. ������ ȣ�� ����: �θ� >> �ڽ�
	Child c;
	/* ��� ��� */
	// Mother construction
	// Child construction

    return 0; 
} 
