#include <iostream>
using namespace std;

/* const �Լ� �����ε� */
/* 
	- const �� ������ �����ε��� ��� ����� �� 
		- const�� ������ ��ü�� const �Լ��� ȣ�� ����
		- const ���� ������ ��ü�� const ���� �Լ� ȣ�� 
	
	- const�� �տ� ���� �Լ�
		- �ܼ��� ������ ������ �� ���� ����� �ϰڴٴ� �ǹ�
	- const�� �ڿ� ���� �Լ�
		- const ��ü�� ����� �� �ִ� �Լ��μ�
		  ��� ���� �������� �ʰڴٴ� �ǹ�
 */
 
#include <iostream>
#include <string>

class Something
{
public:
    string m_value = "default";

    const string& getValue() const
    {
        cout << "const version" << endl;
        return m_value;
    }

    string& getValue()
    {
        cout << "non-const version" << endl;
        return m_value;
    }
}

int main()
{
    Something s1;
    s1.getValue();   // string& getValue() ȣ��
    s1.getValue() = 10; // ���� 

    const Something s2;
    s2.getValue();  // const string& getValue() const ȣ��
}
