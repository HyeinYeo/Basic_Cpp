#include <iostream>
using namespace std;

/* ģ���Լ��� Ŭ���� */
/* 
	- Ŭ�������� � �Լ��� �ٸ� Ŭ������ friend�� ����
	  => �ڽ��� private ����鿡�� �����Ӱ� ������ �� �ְ� ���
	  
	- �Լ��� ģ���� ����
		friend + �Լ��� ����  
	
	- Ŭ������ ģ���� ���� 
		friend class Ŭ������ 
		- ģ�� Ŭ������ ��Ŭ������ ��� private ����鿡 ���� ���� 
		
		- ģ�� ����Լ�
			friend <��ȯ�ڷ���> Ŭ������::�Լ���(); 
			- �ٸ� Ŭ������ �Ϻ� ����Լ����� private ��� ������ ����ϰ� ���� ��
		
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



