#include <iostream>
using namespace std;
/* ������ Ŭ����(Derived class) ���� & �ʱ�ȭ */
/*
	1. public ���
		- protected, public -> ���� ���� ���� ���� �ڽ� Ŭ������ �״�� ��� Ȯ�� 
		 
	
	2. protected ���
		- ��� �ڽ�, ���� Ŭ������ �ȿ��� ����� ����� �� �ְ� �ܺο����� ����� �� ����
		- private����� ��� �ڽ�, ���� Ŭ������ �ȿ����� ���� �Ұ���
		- protected, public -> ��� protected ���� �������� ����Ǿ� �ڽ� Ŭ������ ��� Ȯ��
		
	3. private ���
		- private���� ��� ������ ��ġ "�ڽ� Ŭ���� ��� ��ü�� privateȭ" ��
		- ���� Ŭ����, �� ������ �Ͼ�� ��� ����� �������� ����
			- �Լ��� ���ؼ� �����ؾ� �� 
		- ���� �ڽ� Ŭ���������� ���� ����
		- protected, public -> ��� private ���� �������� ����Ǿ� �ڽ� Ŭ������ ��� Ȯ��

	** ���� ������ ���� �� private�� �ڵ� ó�� 
	 
*/


class Mother
{
public:
    int m_public;
protected:
    int m_protected;
private:
    int m_private;
};

/* 1. public ��� */
class Daughter : public Mother
{
public:
    Daughter()
    {
        m_public = 7;    // ���� 
        m_protected = 7; // ���� 
        // m_private = 7;  // �Ұ��� 
    }
};

/* 2. protected ��� */
class Son : protected Mother
{
public:
    Son()
    {
        m_public = 7;    // ���� 
        m_protected = 7; // ���� 
        // m_private = 7;  // �Ұ��� 
    }
};

/* 3. private ��� */
class Daughter2 : private Mother // ���� ���ڴٴ� �� 
{
public:
    Daughter2()
    {
        m_public = 7;    // ���� 
        m_protected = 7; // ���� 
        // m_private = 7;  // �Ұ��� 
    }
};

class GrandDaughter : public Daughter2
{
public:
    GrandDaughter()
    {
        // m_public = 24;  // �Ұ���
		// m_protected = 24; // �Ұ��� 
        // m_private = 24;  // �Ұ��� 
    }
};

int main()
{
	/* 1. public ��� */
    Daughter daughter;
    daughter.m_public = 100;     // ���� 
    // daughter.m_protected = 100;  // �Ұ���
    // daughter.m_private = 100;  // �Ұ��� 
    
    
    /* 2. protected ��� */
    Son son;
    // son.m_public = 100; // �Ұ��� 
    // son.m_protected = 100; // �Ұ��� 
    // son.m_private = 100; // �Ұ��� 
    
    
    /* 3. private ��� */
    Daughter2 d2;
    // d2.m_public = 100;     // �Ұ��� 
    // d2.m_protected = 100;  // �Ұ���
    // d2.m_private = 100;  // �Ұ���
}
