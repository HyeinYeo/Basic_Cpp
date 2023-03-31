#include <iostream>
using namespace std;
/* �����Լ�: ���� �Ҹ��� */
/*	
	1. �Ϲ��� �Ҹ���
		- ������ ȣ�� ����: ���� >> �ڼ�
		- �Ҹ��� ȣ�� ����: �ڼ� >> ���� 
		
	2. ���� �Ҹ���
		- Derived�� �Ҹ��� ~Derived()�� virtual �Ӽ��� �����ް� �� 
		** �θ� �Ҹ��ڰ� ���� �Ҹ��ڰ� �ƴ϶�� �ڽ� �Ҹ��ڿ� override�� ���� �� ����
		
	** �����ڴ� �����Լ� �� �� ����
		�����ڿ��� �����Լ� ȣ���ص� ���� ���ε� X(�ڽ� Ŭ������ ����(�ʱ�ȭ) ���̶� �������̵��� �����Լ� �ν� �Ұ�) 
		 
*/

/* ���� �Ҹ��� ��� �� */
class Base
{
public:
	~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int *m_array; 

public:
	Derived(int length)
	{
		m_array = new int[length];
	}

	~Derived()  
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};

/* ���� �Ҹ��� ��� ��*/
class Base2
{
public:
	virtual ~Base2() // �Ҹ��� �տ� virtual Ű���� ���̱� 
	{
		cout << "~Base2()" << endl;
	}
};

class Derived2 : public Base2
{
private:
	int *m_array; 

public:
	Derived2(int length)
	{
		m_array = new int[length];
	}

	~Derived2() override // �θ� �Ҹ��ڰ� ���� �Ҹ��ڰ� �ƴ϶�� �ڽ� �Ҹ��ڿ� override�� ���� �� ���� 
	{
		cout << "~Derived2()" << endl;
		delete[] m_array;
	}
};

int main()
{
	// ���� �Ҹ��� 
	// Derived derived(5); // ~Derived() ~Base() ȣ�� 
	
	// ������
	Derived *derived1 = new Derived(5); // ���� �Ҵ�
    Base *base1 = derived1;  // ������, �����Ҵ�
    delete base1; // ~Base() ��� 
    // => Derived �Ҹ��ڴ� ȣ�� ���� �ʰ� �θ��� Base �Ҹ��ڸ� ȣ��
    // �θ� ����� �θ� �Ҹ��ڸ� ȣ��Ǹ� �ڽ� �Ҹ��ڴ� ȣ����� ����
	// �޸� ���� ���� �߻� ����
	
	
	// ���� �Ҹ���
	Derived2 *derived2 = new Derived2(5); // ���� �Ҵ�
    Base2 *base2 = derived2;  // ������, �����Ҵ�
    delete base2; 
    /* ��� ��� 
		~Derived2()
		~Base2()
	*/

	return 0;
}
