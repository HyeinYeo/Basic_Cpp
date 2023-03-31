#include <iostream>
using namespace std; 
/* ��� �Լ� ������ */
/*
	- virtual Ű���尡 ���� ���·� �������̵� �ϴ� ���
		- �������� �ڷ���(�θ�Ŭ���� �ڷ��� VS. �ڽ�Ŭ���� �ڷ���)�� ���� �Լ��� ȣ���
		- ������ Ÿ��, ���� ���ε� 
		
	<-> �����Լ� �������̵�
		- �� ĳ������ ������(�θ�Ŭ���� �ڷ��� �����Ϳ� �ڽ� ��ü ����)
		- �ڽ� ��ü�� virtual �������̵��� �Լ��� ����
		- �� Ÿ��, ���� ���ε�  
*/

class Base{
public:
	void f(){ cout << "Base::f() called" << endl; }
};
class Derived : public Base{
public:
	void f(){ cout << "Derived::f() called" << endl; }
};

int main(){
	Derived d, *pDer; // '�ڽ�Ŭ���� �ڷ��� ������'�� �ڽ� ��ü ���� 
	pDer = &d;
	pDer->f(); // �ڽ�Ŭ������ �����ǵ� �Լ� ȣ��
	
	Base *pBase = pDer; // '�θ�Ŭ���� �ڷ��� ������'�� �ڽ� ��ü ����(�� ĳ����) 
	pBase->f(); // �θ�Ŭ������ ���ǵ� �Լ� ȣ�� 
	
	/* ���� ��� 
		Derived::f() called
		Base::f() called
	*/
}


