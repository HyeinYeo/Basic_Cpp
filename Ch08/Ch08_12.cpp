#include <iostream>
using namespace std;

/* friend �Լ��� Ŭ���� */
/* 
	- Ŭ�������� � �Լ��� �ٸ� Ŭ������ friend�� ����
	  => �ڽ��� private, protected ����鿡�� �����Ӱ� ������ �� �ְ� ���
	  - only �Լ��� ������ ����
	  - ������ ������ ����! 
	  - private, public �ƹ� ���� ������ ���� ���� 
	  
	1. �ܺ� �Լ��� ģ���� ����
		- Ŭ���� ���� �ƹ� ���� �������ָ� ��. 
			friend + �Լ��� ����  
	
	2. �ٸ� Ŭ������ ģ���� ����
		1) �ٸ� Ŭ������ �Ϻ� ����Լ��� friend�� ����
			- �ٸ� Ŭ������ �Ϻ� ����Լ����� private, protected ��� ������ ����ϰ� ���� ��
				friend <��ȯ�ڷ���> Ŭ������::�Լ���(); 
		
		2) �ٸ� Ŭ���� ��ü ����Լ��� friend�� ����
			- ģ�� Ŭ������ ��Ŭ������ ��� private ����鿡 ���� ����	
				friend class Ŭ������;
			
	
	* ��������
		- �ڿ��� ����� �̸��� �̸� ����(���)�ϴ� ���
		- ������ ������ ó���� 
		
	* ���漱�� 
		- �����Ϸ����� Y Ŭ������� ���� �ִٴ� ���� X Ŭ���� ���� ���� �̸� �˷��ִ� ��
		 

 */

/* �Լ��� ģ���� ���� */
class A
{
private:
    int m_value = 1;
    friend void doSomething(A& a);  // ģ���� ����
};

void doSomething(A& a)
{
    cout << a.m_value << endl; // friend ������, ���� �߻� 
}

/* ���� ���� */
class Y; // �̸� ������Ÿ�Ը� ���� ����

class X
{
private:
    int m_value = 1;
    friend void doSomething2(X& x, Y& y);  // ���� �߻� 
    // ���� B Ŭ������ ����Ǳ� ���̱� ������ doSomething2�� �Ű������� Y& y �� ���� Y�� ������ �� 
};

class Y
{
private:
    int m_value = 1;
    friend void doSomething2(X& x, Y& y);  // ģ���� ����
};


void doSomething2(X& x, Y& y)
{
    cout << x.m_value << endl; // friend ������, ���� �߻� 
    cout << y.m_value << endl;
}

/* Ŭ������ ģ���� ���� */
class Q; // ���漱��
 

class P
{
private:
    int m_value = 1;
	
	// Q Ŭ������ ģ���� ���� : P Ŭ������ ��� private ����鿡 ���� ����
    friend class Q;   
    
    // ģ�� ����Լ� : �Ϻ� ����Լ����� private ��� ������ ���
	friend void Q::func_2(P& p);  // Q�� Ư�� ��� �Լ��� ģ���� ����
    
    
};


class Q   // P Ŭ������ ��� private ����鿡 ���� ���� 
{
private:
    int m_value = 1;

    void func_1(P& p)   
    {
        cout << p.m_value << endl; // Q
    }

    void func_2(P& p)   
    {
        p.m_value++;
    }
};


/* ģ�� ����Լ� : �Ϻ� ����Լ����� private ��� ������ ��� */
class F; // G Ŭ������ ��������� �Ű����� F& f���� F�� �𸣱� ������ ���漱��  

class G   
{
private:
    int m_value = 1;

    void func_1(F& f)   
    {
        cout << f.m_value << endl; // ���� �߻� 
    }

    void func_2(F& f);   // �� �Լ��� F Ŭ������ private ����� ���� ���� 
    // F�� G �ڿ� ������ F�� ���� ���̶� F�� m_value�� �� �� �����Ƿ�,
    // ���⼭ �Լ��� ���� �ϰ� ���Ǵ� F Ŭ���� �Ŀ� �Ѵ�. 

};

class F
{
private:
    int m_value = 1; 
    
    // ģ�� ����Լ�
	friend void G::func_2(F& f);  // G�� Ư�� ��� �Լ��� ģ���� ����
};

void G::func_2(F& f){ // G Ŭ������ ģ�� ����Լ� ���Ǵ� ���⼭!!!! 
    f.m_value++;
} 



