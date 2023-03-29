#include <iostream>
using namespace std;

/* ����(static) ��� ���� */
/* 
	- static ��� ���� 
		- ��� ��ü�� �� �޸𸮸� �����ϴ� ��� ����(��� ��ü�� �����ϴ� ��� ����)
			cf. python Ŭ���� ���� 
			- ���α׷� ���۶����� �޸� ����
				- ���α׷� ���� ������ �޸𸮿� �� ����
				- ��ü ���� ������ �޸� ����
				- ��ü ���� ��, �ʱ�ȭ �ʼ� 
			
			- ��ü�� ���������� ����
			- ��ü �̸�, Ŭ���� �̸����ε� ���� ���� 
		
		1. �ݵ�� ������������ �ʱ�ȭ(����) 
			<�ڷ���> Ŭ������::static���� = �ʱ�ȭ��; 
		
			- �ܼ� ������ ���� �޸𸮸� ������� �ʱ� ����
			- ���Ǵ� ���� �޸� �Ҵ�
			
			- Ŭ���� ��: "����"�� ����, ���Ǵ� �Ұ���
			- ��������: ���� �ʼ� 
			
			- main �Լ��� �����̰� ������ �ȿ����� �ʱ�ȭ �� �� ���� 
			
		2. ���� �� �ʱ�ȭ�� ��� ���� �������� �Ұ���
	
	- static const ��� ����
		1. Ŭ���� ������ �ʱ�ȭ �ϴ� �� ����
			- ���� �����ϴ� ���� �Ұ����ϱ� ����
			- �� ��� �״�θ� ��� ��ü�� ����
			
		2. ������� �������� �ʱ�ȭ�� ����
			
	
	- private�� static ��� ���� �ʱ�ȭ
		1. private�ϴ��� Ŭ���� "�ܺ�"���� ���ǰ� ����!!!
			- static����� Ŭ���� ���ο��� �ʱ�ȭ�� �Ұ����ϹǷ�
			
	- static ��� ������ Ŭ���� ���ο��� �ʱ�ȭ
		- inner-class�� ���
			- Ŭ���� �ȿ� Ŭ������ �ϳ� �� ����� �� Ŭ������ ������ �ȿ��� �ʱ�ȭ
			- Ŭ�������� ���� Ŭ������ Ŭ���� ��ü�� static ��� ������ ����
			
 */
 
class Something
{
public:
	static int m_value; // ����...
	static const int m_value2; // static const ����!
};

int Something::m_value = 1; // ���� �������� �ʱ�ȭ


// private static ��� ���� �ʱ�ȭ
class A
{
private:  
	static int s_value;
}; 

int A::s_value = 0; // ����! 

// inner-class
class Something2
{
public:
	class _init // inner class
	{
	public:
		_init()
		{
			s_value = 9876; // s_value ���� ����.
		}
	};

private:
	static int s_value; 
	static _init s_initializer; // ���� Ŭ���� ��ü�� static ��� ������ ����
};
Something::_init Something::s_initializer; // ���� �������� static ��� ������ s_initializer�� ����

int main()
{
    // int Something::m_value = 1;  ����!!! ���� ���������� ����. 

    cout << Something::m_value << endl;  // 1 ���, ��ü ���� ������ ��� ����
    cout << &Something::m_value << endl;  // 0x472010 ���, ��ü ���� ������ ��� ����

    Something st1;
    Something st2;

    st1.m_value = 2;

    cout << st1.m_value << endl;  // 2 ��� 
    cout << &st1.m_value << endl; // 0x472010 ���

    cout << st2.m_value << endl;  // 2 ���
    cout << &st2.m_value << endl; // 0x472010 ���

    st2.m_value = 1024;

    cout << Something::m_value << endl; // 1024 ���
    
    
    // ---------------------------------------------------
    A a;
	cout << a.s_value << endl;

	//A::s_value = 1;  // ����! private�̹Ƿ� s_value �� ���� �Ұ��� 

    return 0;
}
