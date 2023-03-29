#include <iostream>
using namespace std;

/*��ü���� & Ŭ����*/

/*
	1. Ŭ����
		- ����� ������(��� ����), ���(��� �Լ�)���� ���� �׷�ȭ �� ��
		- �������� �����Ϳ� ��ɵ��� ��� �߻�ȭ �� ��
		- ���� ��üȭ �Ǿ� �޸� �� �����ϴ� ���� �ƴϱ� ������ �ּҸ� �� �� ����
		
		- �Լ� ��� �� �Ű������� ���� �Ѱ��� �ʿ䰡 ���� 
		
	2. ��ü
	 	- Ŭ������ Ʋ�� ��� �޸� �� �����ϰ� �� ��
	 	- ��ü���� ������ ������ ���� ��� �ٸ�
		- �� ��ü�� ���� ������
		- ��ü�� �޸� �� �����ϴ� ���̹Ƿ� �޸� �ּҸ� �� �� ���� 
		
	3. Ŭ���� vs. ����ü 
		- Ŭ����
			- ���� ������ ����
				- public 
				- private
				- protected 
			-  ������(�������)�� ���(����Լ�)�� ���� 
			
		-  ����ü
			- �ַ� ������(��� ����)�� ���� 
			
	cf. Java
		- Java ���� ��ü ������ new ��� 
*/

class Friend
{
public:
	string _name;
	string _address;
	int _age;
	double _height;
	double _weight;

	void print() // �Ű������� �� �־ �� 
	{
		cout << _name << " " << _address << " " << _age << " " << _height << " "
			<< _weight << endl;
	}
};


int main()
{
	Friend rachel; // ��ü ���� 

    rachel.name = "Rachel";
    rachel.name = "Seoul";
    rachel.name = 2;
    rachel.name = 30;
    rachel.name = 10;


	rachel.print();   // ���! 

	return 0;
}
