#include <iostream>
#include <cassert>
using namespace std;
/* ���� ���� & ���� ���� */
/*	
	1. ���� ����
		- ������ ���� �ּҸ� �����Ͽ� �Ѱ��ִ� ��
		- ���� �߻� ����
		 
	2. ���� ����
		- ���ο� �޸𸮸� �Ҵ�޾� Ȯ���� �� �� ������ ���빰�� ������ ���� ��
		
	3. ���� ������ vs ���� ������ �����ε�
		- ���� ������
			- �������̹Ƿ� ��ü�� �����Ǵ� �������� ������ �ִ� ��� ȣ��
			 MyString str1("Hello");

			 MyString str2(str1);  // ���� ������ ȣ��
			 Mystring str3 = str1; // ���� ������ ȣ��
		
		- ���� ������ �����ε� 
			- �ܼ��� �̹� �����ϴ� ��ü������ ���� �� ȣ�� 
			- �ڱ� �ڽ��� ���� ���� �޸𸮸� ����ִ� ���� �ʿ�
				- why? �ڱ� �ڽſ��� �ٸ� ��ü�� �����Ͽ� ���� ����� ���̹Ƿ� 
			 MyString str1("Hello");
			 MyString str2;  
			 // �̹� ������ ��ü str1, str2 
			 str2 = str1;  // ���� ������ �����ε� ȣ��
		
		
*/

class MyString
{
public:
	char *m_data = nullptr; 
	int m_length = 0;

	MyString(const char *source = "") 
	{
		assert(source);  // ���ڿ� �μ��� �� �޾ƾ� ��!

		m_length = std::strlen(source) + 1; 
		m_data = new char[m_length]; 
	
		for (int i = 0; i < m_length; ++i) 
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0'; // ���ڿ� �������� �� ���� �ٿ��� 
	}
	
	// ���� ������ : ���� ���� ����
	MyString(const MyString &source) 
	{
		m_length = source.m_length; 
	
		if (source.m_data != nullptr) 
		{
			m_data = new char[m_length];  // ���� �޸� �Ҵ� 
	
			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i]; // for�� ������ ������ ����
		}
		else
			m_data = nullptr;	
	} 
	
	/* ���� ������ �����ε� */
	MyString& operator = (const MyString &source)
	{
		if (this == &source)   // �ڱ� �ڽ��� �����ϴ� ���, ex) hello = hello; 
			return *this; // �ڱ� �ڽ� ���� 
	
		delete[] m_data;   // �ڽ��� ���� ���빰 ����ֱ� 
	
	    /* �Ʒ� ������ ��������� ���� ���� ������ ���� */
	
		m_length = source.m_length;
	
		if (source.m_data != nullptr)
		{
			m_data = new char[m_length]; // ���� �޸� �Ҵ� ���� 
	
			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
	    else
	        m_data = nullptr;
	} 

	~MyString()  
	{
		delete [] m_data; // �� �Ҵ� �޸� ���� 
	}
};

int main()
{	
	/* ���� ���� ������ */
	MyString hello("Hello");

	cout << (int*)hello.m_data << endl; 
	cout << hello.m_data << endl; // Hello ��� 

	{
		MyString copy = hello; // ����Ʈ ���� ������ ȣ��

		cout << (int*)copy.m_data << endl;
		cout << copy.m_data << endl; // Hello ��� 
		
		// ������ �����鼭 copy ��ü �Ҹ�
		// �Ҹ��� ȣ��Ǹ鼭 �ּҸ� �����ߴ� "Hello" �޸𸮵� ������ 
	}

	cout << hello.m_data << endl; // �̻��� ���� �����, ������ �޸��� �����Ⱚ ��� 
	
	
	/* ���� ���� */
	MyString hello("Hello");

	cout << (int*)hello.m_data << endl; 
	cout << hello.m_data << endl;

	{
		MyString copy = hello;  // ���� ������ ȣ��, ���� ���� 

		cout << (int*)copy.m_data << endl;
		cout << copy.m_data << endl;
	}

	cout << hello.m_data << endl;
	
	/* ���� ������ �����ε�*/
	MyString hello("Hello");

	cout << (int*)hello.m_data << endl; 
	cout << hello.m_data << endl;

	{
        Mystring copy;
		copy = hello;  // �����ε� �� ���� ������ ȣ��

		cout << (int*)copy.m_data << endl;
		cout << copy.m_data << endl;
	}

	cout << hello.m_data << endl;

	return 0;


	return 0;
}
