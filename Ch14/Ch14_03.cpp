#include <iostream>
using namespace std;
/* ����Ŭ����: ����� ���� �ڷ��� */
/*	
	1. ���� Ŭ���� 
		- throw�� ���� Ŭ������ ����Ͽ� � �������� ǥ��
		- ���� Ŭ������ '�͸� ��ü'�� ������ �� throw
	
	2. ���� Ŭ���� ���
		��ü �߸� ���� �߻� ��, 
		1) catch ���� �ٲٱ�
		2) virtual : �θ� ���� Ŭ�������� ���� �Լ��� ����
		3) throw;�� ������ 
		
	3. catch�� �ȿ��� re-throw�ϱ�
		- ���� �ǰ����ؼ� �˸´� catch�� ã�� ��! 
		- throw;�� ������ ��ü �߸� �� �Ͼ 
	 

*/
class Exception // ���� Ŭ���� ��ü
{
public:
    void report()
    {
        cout << "Exception report" << endl;
    }
};

class MyArray
{
private:
    int m_data[5];
public:
    int & operator [] (const int & index)
    {
        if (index < 0 || index >= 5) throw Exception(); // ���� Ŭ���� �͸� ��ü ���� & throw 
        return m_data[index];
    }
};

void doSomething()
{
    MyArray my_array;
    
    try
    {
        my_array[100];
    }
    catch (const int &x)  
    {
        cerr << "Exception " << x << endl;
    }
    catch (Exception &e) // throw Exception(); ����
    {
        e.report();
    }
}


/* 2. ���� Ŭ���� ��� */ 
class Exception2
{
public:
    void report()
    {
        cout << "Exception2 report" << endl;
    }
    
    /*
	virtural void report() // virtual ���� 
    {
        cout << "Exception2 report" << endl;
    }
	*/
};

class ArrayException2 : public Exception2
{
public:
    void report()  // �������̵�
    {
        cout << "Array Exception2 report" << endl;
    }
};

class MyArray2
{
private:
    int m_data[5];
public:
    int & operator [] (const int & index)
    {
        if (index < 0 || index >= 5) throw ArrayException2();
        return m_data[index];
    }
};

void doSomething2()
{
    MyArray2 my_array;
    
    try
    {
        my_array[100];
    }
    catch (const int &x)
    {
        cerr << "Exception2 " << x << endl;
    }
    catch (ArrayException2 &e)
    {
        e.report();
        throw e;  // re-throw
    }
    
    catch (Exception2 &e)
    {
        e.report();
        throw;
    }
}

int main()
{
	try{
		doSomething();
	
		cout << "main" << endl;
		
		cout << "=========================" << endl;
		doSomething2();
		
		cout << "main2" << endl;
	}
	catch (ArrayException2 &e) // re-throw�� ���� catch�� 
    {
       cout << "main()" << endl;
       e.report();
    }
    
    /* ���� ���
		Exception report
		main
		=========================
		Array Exception2 report
		main()
		Array Exception2 report 
	*/
	return 0;
}
