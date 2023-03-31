#include <iostream>
using namespace std;
/* ����ó�� & ���� �ǰ���(stack unwinding) */
/*	
	1. ���� �ǰ��� => ������ ���� 
		- throw ������, �˸´� catch�� ã�� ������(�˸��� ���� ó���� ���� ������) 
		  �� �Ʒ� ��� �κе��� ��ŵ�� ä�� ���� �ǰ���
		  	-  throw ���ܰ� �Ͼ �ٷ� �Ʒ� �κп��� ã�� �ʰ�, �ٷ� Skip �� ���� �ǰ��⸦ ���� �˸��� catch Ž�� 
		- �˸��� catch�� ã�� ���� ã�� ���� ���ĺ��� catch �̿��� �Ʒ� �κе��� �� ���� ����
		
		**������ ����
			- throw�� �Լ� ���� ����ó�� ��ƾ�� ���� ���, ����ó�� ��ƾ �߰��� ������ caller �Լ��� ���� ���� 
	
	2. catch(...) 
		- ��� ������ Ÿ���� �� ���� �� �ִ� catch
	
	- �Լ�() throw()
		void ex1() throw(int)
			- �� �Լ��� int Ÿ���� ���� �޼����� ���� ���� �ִٴ� �ǹ�
		
		void ex2() throw(...)
			- �� �Լ��� � Ÿ���� ���� �޼����� ���� ���� �ִٴ� �ǹ�
			
		void ex3() throw()
			- �� �Լ��� ���ܸ� �߻���Ű�� �ʴ´ٴ� �ǹ�
			- �Լ� ������ throw ��� �� ���� �߻� 

*/
void last()
{
	cout << "Last" << endl;  // 5 
	cout << "Throws exception" << endl;  // 6 

	throw -1;
	cout << "End Last" << endl; // ���� X 
}

void third()
{
	cout << "Third" << endl; // 4

	last();

	cout << "End third" << endl;  // ���� X
}

void second()
{
	cout << "Second" << endl; // 3 

	try
	{
		third();
	}
	catch (double)
	{
		std::cerr << "Second caught double exception!" << endl;  // ���� X
	}
	cout << "End second" << endl;  // ���� X 
}

void first()
{
	cout << "First" << endl;  // 2

	try
	{
		second();
	}
	catch (int)
	{
		std::cerr << "first caught int exception!" << endl; // 7, throw -1 ĳġ!
	}
	cout << "End first" << endl; // 8
}

int main()
{
	cout << "Start" << endl;  // 1 

	try
	{
		first(); 
	}
	catch (int)
	{
		std::cerr << "main caught int exception!" << endl;  // ���� X 
	}
	cout << "End of main" << endl; // 9
}
