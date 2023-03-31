#include <iostream>
using namespace std;
/* ���� ���ε� & ���� ���ε� */
/*	
	1. ���� ���ε� 
		- ����(��Ÿ��) ���� �ʴ� ���¿����� � �Լ��� ȣ����� ����� �� �� �ִ� ���. 
		- ������, ���� Ÿ�ӿ� �̹� ������, �Լ� �̸����� �� ����ϰ� ����
		- ���� �߿� ���� �Լ��� ã�ư��� �ϴ� �� ���� 
		
		- �����
			- ����: ������ �Լ��� �̹� ���� ������ ����
			- ������ ������
			 
	2. ���� ���ε� 
		- � �Լ��� ȣ������� ��Ÿ�� �߿� ����
		- ��Ÿ�� �� ���� �Լ� �����͸� ���� �ش� �Լ��� ã�ư� ȣ��
		- ��Ÿ�� �� �����Ϳ� ����� �ּ� ���󰡼� �Լ� ȣ�� 
		
		- �����
			- ����: ��Ÿ�� �߿� �Լ��� �����͸� ���� ���� �Լ��� ã�ư� ����
			- ����, ������ ���� 
		 
*/

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}


int main()
{
	/* 1. ���� ���ε� */
    int x1, y1;
    cin >> x1 >> y1;

    int op;

    cout << "0: add, 1: subtract" << endl;
    cin >> op1;

    int result;
    switch(op1)
    {
        case 0 : result = add(x, y); break;
        case 1 : result = subtract(x, y); break;
    }
    
    /* 2. ���� ���ε� */
    int x2, y2;
    cin >> x2 >> y2;

    int op2;

    cout << "0: add, 1: subtract" << endl;
    cin >> op2;

    int(*func_ptr)(int, int) = nullptr;
    switch(op2)
    {
        case 0 : func_ptr = add; break;
        case 1 : func_ptr = subtract; break;
    }
}
