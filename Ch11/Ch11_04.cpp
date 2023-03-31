#include <iostream>
using namespace std;
/* ������ Ŭ����(Derived class) ���� & �ʱ�ȭ */
/*
	1. Ŭ���� ũ��
		- �ڽ� Ŭ������ �������� �θ� Ŭ������ ����� ���� => ũ�⵵ ������ ũ��
		- �θ� Ŭ�������� ������ ū �޸� ������ �Ҵ� ���� 
	
	2. ������ ȣ���� �θ����, �Ҹ��� ȣ���� �ڽĺ���
	 
*/

/* 1 - 1) int, int */
class Mother
{
    int m_i;
};

class Child : public Mother
{
    int m_d;
};

/* 1 - 2) int, double */
class Mother2
{
    int m_i;
};

class Child2 : public Mother 
{
    double m_d;
};

/* 2. */
class A
{
public:
	A(int a)
	{
		cout << "Constructor A"<< endl;
	}
	
	~A()
	{
		cout << "Destructor A " << endl;
	}
};

class B : public A
{
public:
	B(int a, double b)
		: A(a)
	{
		cout << "Constructor B" << endl;
	}

	~B()
	{
		cout << "Destructor B " << endl;
	}

};

class C : public B
{
public:
	C(int a, double b, char c)
		: B(a, b)
	{
		cout << "Constructor C" << endl;
	}

	~C()
	{
		cout << "Destructor C " << endl;
	}
};

int main()
{
    cout << sizeof(Mother) << endl;   // 4 ���  (int)
    cout << sizeof(Child) << endl;    // 8 ���  (int + int)  �������� m_i�� �ڽŸ��� m_d
    
    cout << sizeof(Mother2) << endl;   // 4 ���  (int)
    cout << sizeof(Child2) << endl;    // 16 ���  (int + double)  �������� m_i�� �ڽŸ��� m_d
    								  // padding ������ 4 + 8 = 12�� �ƴ� 4 (+ 4) + 8 = 16 ��� 
    								  
    								  
    C c(1024, 3.14, 'a');
    /* ��°�� 
	Constructor A
	Constructor B
	Constructor C
	Destructor C
	Destructor B
	Destructor A
	*/
}
