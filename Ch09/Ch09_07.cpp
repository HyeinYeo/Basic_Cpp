#include <iostream>
using namespace std;
/* ��ȣ ������ �����ε� */
/*	
	<��ȣ ������>
		()
	
	<��ȣ ������ �����ε�>
		- () => �ַ� �Լ� ȣ���� �� ���
		- ��ü(�μ�)�� �Լ�ó�� �����ϰ� ���� �� ����ϴ� ������ �����ε�
		- **��� �Լ��θ� ������ ����!!!	
*/

class Accumulator
{
private:
	int m_counter = 0;

public:
	int operator () (int i) 
    { 
        return (m_counter += i); 
        // ���� ���� ���� �� �����Ͽ� ���� 
    } 
};

int main()
{
	Accumulator acc;

	cout << acc(10) << endl; // 10 ���
	cout << acc(20) << endl; // 30 ���

	return 0;
}
