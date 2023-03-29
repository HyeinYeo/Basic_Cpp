#include <iostream>
using namespace std;

/* �Ҹ��� */

/*	
	1. �Ҹ��� 
		- ��ü�� ������ ����� �޸𸮿��� ������ �� "�ڵ�����" ȣ��Ǵ� �Լ� 
			cf. ������: ��ü�� �޸𸮸� ������ ��, �� ��ü�� ������ �� ���α׷��Ӱ� ���� ȣ���ϴ� �Լ�
			
		- �ν��Ͻ��� �޸𸮿��� ������ ��, ���ο��� �ڵ����� ȣ��
			- �����Ҵ�(new)���� ������� ���� �ڵ����� �޸� ���� X
			- delete�� �Ÿ� ������ ���� �Ҹ��� ȣ�� 
	
	2. ȣ�� ���� : ~ Ŭ�����̸�()
		- �Ҹ��ڴ� �μ��� ���� ����. �Ű� ���� ����.
		- �ڵ����� ȣ��Ǵ� �Լ��̸� ���α׷��Ӱ� ���� ȣ���ϴ°� �������� ����
	
		- ��ü�� ���� ������ ����� �� �޸𸮰� �ݳ� �Ǹ鼭 �Ҹ��� ȣ�� 
		- ** ���� ���߿� ������� ��ü�� ���� ����� 
			- ���� �޸𸮸� ����ϹǷ� ���� ���߿� ������� ��ü�� ���� ���� ����
			
	3. Ȱ��
		- �޸� ���� ����
			- �޸𸮸� ���� �Ҵ� �޴� ����� ���� �� �Ҹ��� �ȿ��� �� ����� delete ���ָ� �޸� ���� ����
	
	
*/
class Simple
{
private:
	int m_id;

public:
	Simple(const int& id_in)
		: m_id(id_in)
	{
		cout << "constructor" << m_id << endl;
	}

	~Simple()  // �Ҹ���
	{
		cout << "Destructor" << m_id << endl;
	}
};

// Ȱ��(�����Ҵ� ����)
class IntArray
{
private:
	int *m_arr = nullptr;
	int m_length = 0;
	
public:
	IntArray(const int& length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];  // m_arr ����� �����Ҵ� �ް� �ִ�.

		cout << "constructor" << endl;
	}

    ~IntArray()
    {
		if (m_arr != nullptr) 
        	delete [] m_arr;  // ��ü �Ҹ�� m_arr ����� �������ֱ�!
    }

	int getLength() {return m_length;}
	
}; 

int main()
{
	Simple s1(0);  // ������ ȣ��, m_id = 0
	Simple s2(1);  // ������ ȣ��, m_id = 1
	

	//return 0;  // ������ ����鼭 �� ��ü ��� �Ҹ��� ȣ��
	
	/* ��� ��� 
	constructor0
	constructor1
	Destructor1 // 1�� ��ü�� ���� �Ҹ��� ȣ��� 
	Destructor0
	*/
	
	// -------------------------------------------------------
	while (true) 
	{
		IntArray my_int_arr(10000);
	}
	// return 0;
	/*
	- ��ü ������ m_arr ����� �޸𸮸� �������� �Ҵ����
	- delete �� �ϴ� ��� -> ��ü�� �������� �����ϹǷ� �޸� ���� �߻�
	- �Ҹ��ڿ� m_arr ����� delete �ڵ� ���� 
		->  while�� �ȿ��� ���� �ݺ����� �Ѿ ������ ��ü�� �Ҹ�(�Ҹ��� ȣ��)
	
	
	return 0;
}
