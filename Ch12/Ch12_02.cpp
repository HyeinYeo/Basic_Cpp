#include <iostream>
using namespace std;
/* �����Լ� & ������ */
/*	
	- �����ϰų� ����Ű�� ��ü�� Ÿ���� �ƴ϶�, �����ϴ� ���� Ȥ�� �������� Ÿ���� �����̳Ŀ� ���� ��� ȣ��
	  B b;
	  A &ref1 = b;
	  ref1.print();
	  	- BŸ�� ��ü�� b�� �����ϰ� �ִ���, ref1�� AŸ���̱� ������ ref1.print(); A�� print() ȣ��
	  
	- virtual
		- �����ϴ� ��ü�� Ÿ���� �����̳Ŀ� ���� ȣ��
			- �θ� �����ͷ� ȣ���ϴ���, �ڽ��� �������̵��� �Լ� ȣ��
		- ���� Ŭ���� virtual ���� �Լ��� ���ռ� ����
			- ���� ���ĵ� �ڽ� Ŭ�������� virtual�� �ٿ� ���� �ʴ��� �״�� �����Լ� Ư�� ����
	
	- ���� ���ε�
		- �����Լ� ȣ�� ��, ���� �߿� �ڽ� Ŭ���� ��ü ���� �������̵��� �����Լ��� �������� ã�� ȣ��
		- �ڽ� Ŭ���� ��ü�� ����, �θ� Ŭ���� �����ͷ� �����Լ� ȣ��� �� ���� ���ε�
		* ���� ���ε� �߻��ϴ� ���
			- �θ� Ŭ���� ���� ����Լ��� �����Լ� ȣ�� 
			- �ڽ� Ŭ���� ���� ����Լ��� �����Լ� ȣ��
			- main()�� ���� �ܺ��Լ�����, �θ�Ŭ������ �����ͷ� �����Լ� ȣ��
			- �ٸ� Ŭ�������� �����Լ� ȣ��			
	**  "�������̵�" : ���ϱ��Ա����� ���ƾ� �� 
	 
*/
class A
{
public:
	// void print() { cout << "A" << endl; }
	virtual void print() { cout << "A" << endl; }
}; 

class B : public A
{
public:
	void print() { cout << "B" << endl; }
};

class C : public B
{
public:
	void print() { cout << "C" << endl; }
};

class D : public C
{
public:
	void print() { cout << "D" << endl; }
};

int main()
{
	A a;
	B b;
	C c;
	D d;

    A &ref1 = b;
    ref1.print();
    // virtual ��: A ���
    // virtual ��: B ��� 

	C &ref2 = d;
	ref2.print();
	// virtual ��: C ���
    // virtual ��: D ��� 

	return 0;
}
