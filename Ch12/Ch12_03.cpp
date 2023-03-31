#include <iostream>
#include <typeinfo> 
using namespace std;
/* �����Լ�: override, final, ���� ��ȯ�� */
/*	
	1. override
		- ����Ÿ�� + �Լ��̸� + �Ű����� ���� + const �������� �Ȱ��ƾ� ��
		- �ٸ���? �������̵��� �ƴ϶� �����ε��� ��
		
		- override Ű����
			- �������̵� �� �Լ���� ����
			- �������̵��� ����� �ȵ����� ������ ���� �߻�
			
	2. final
		1) �ڽ� Ŭ�������� �������̵��� ���ϵ��� ���ƹ���
		2) Ŭ���� ��ü�� ��ӵ��� ���ϰ� ���ƹ��� 
		
	3. ���� ��ȯ��
		 - ���� Ÿ���� �ٸ����� �������̵��� �Ǵ� ���
		   ==> this (�ڱ� �ڽ��� ����Ű�� ������)�� �����ϴ� �Լ��� ���
		       A �� B �� �θ� �ڽ� �����̱� ����
		 
*/

class A
{
public:
    virtual void print(int x) { cout << "A" << endl; }
    
    virtual void print2(int x) { cout << "AA" << endl; }
    
    // 3. ���� ��ȯ��
	virtual A* getThis() 
    { 
		cout << "A::getThis()" << endl;
		return this; 
    }
    void print3() { cout << "AAA" << endl; }
};


class B : public A
{
public:
	// 1. override Ű����
    void print(int x) override { cout << "B" << endl; } 
    
    // 2. final Ű���� 
    //	- �������̵��� B Ŭ���������� ������, �� ���� �ڽ� Ŭ�������ʹ� �� �Լ� �������̵� �Ұ��� 
    void print2(int x) final { cout << "BB" << endl; }
    
    virtual B* getThis() // ��ȯŸ�� �ٸ����� �������̵� ���(this ��ȯ�ϹǷ�) 
    { 
		cout << "B::getThis()" << endl;
		return this; 
    }
    void print3() { cout << "BBB" << endl; }
};

class C : public B
{
public:
    // void print2()  { cout << "CC" << endl; }  // ���� �߻� 
};


int main()
{
	// 3. ���� ��ȯ�� 
	A a;
	B b;

	A &ref = b;
	b.getThis()->print3();
	/* ��� ���
		B::getThis()
		BBB
		
		B�� getThis() ȣ��, b.getThis()���� B* ��ȯ 
	*/
	ref.getThis()->print3(); 
	/* ��� ��� 
		B::getThis()
		AAA
		
		B�� getThis()�� ȣ���ؼ� this�� ����,
		this�� �������� Ÿ���� A�� ��ȯ��
		A�� print3() ȣ�� 
	*/ 

	cout << typeid(b.getThis()).name() << endl;  // class B* ���
	cout << typeid(ref.getThis()).name() << endl; // class A* ���

	return 0;
}
