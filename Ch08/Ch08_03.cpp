#include <iostream>
using namespace std;

/* ������ */

/*
	1. ������ 
		- ��ü�� �޸𸮿� �����ڸ��� ����Ǵ� �Լ�.
		- ��ü�� �������ڸ��� ����Ǵ� �Լ�
		- �ַ� ������� �ʱ�ȭ�ϴ� ������ ��
		

	2. ��� ��� 
		- ** �̸��� Ŭ������ �̸��� ���� 
		- ** ��ü�� �������ڸ��� ����Ǿ�� �ϹǷ� public
			- private�� ���� ��쵵 ���� 
		 
	3. ���ǻ���
		- ������ �Լ� �Ű����� ���� �� ��ü ���� �� ��!! ��ȣ �� 
			- Fraction f; // Fraction ������ �Ű����� ���� ��� 
			- () ��ȣ�� �Ű����� �ִ� �����ڸ� ȣ���� ���� ��� 
		
		- �Ű�����, �Ű������� ����Ʈ�� ��� ���� 
		
		- Ŭ���� �ȿ� ������ ���ǰ� �ƿ� ���� ��
			- �ƹ� �ϵ� ���ϴ� Fraction() {} �Ű����� ���� �⺻ �����ڰ� ���� ����
			- Fraction frac; ��ü�� �����ϸ� �����ִ� �⺻ �����ڰ� ȣ��� 
			- �Ű������� ������ �ִ� �����ڰ� �ϳ��� ������,
			  �Ű������� ���� �����ڴ� �����Ƿ� �⺻ �����ڴ� ȣ�� �Ұ���
			  
			- �⺻ ������ ���� �ÿ��� �Ű����� �ִ� �����ڿ� �ߺ��� �� �ֱ� ������ ��뿡 ���� 
			  	Fraction()   // �⺻ ������
			    {
					numerator = 5; 
					denominator = 8;
				}
			    
				Fraction(const int &num_in = 1, const int &den_in = 1)  // �浹! 
				{
					numerator = num_in;  
					denominator = den_in;
				}
				
		- ���� �ʱ�ȭ(copy initialization) 
			Fraction f = Fraction{1, 3}; // ���� X 
			  
	4. ������ ȣ��� ()�� {}�� ����
		- {}�� ����Ͽ� ȣ���ϴ°� �� ����
		- �ڵ����� ����ȯ ������ ����
		Fraction �����ڿ��� �μ��� int�� ���� ��, 
			Fraction frac{1.0, 3.0}; // ���� O
			Fraction frac(1.0, 3.0); // ���� X
		
		
*/

class Fraction
{
private:
	int numerator; // ����
	int denominator; // �и� 
	
public:
	Fraction()   // �⺻ ������
    {
		numerator = 5; 
		denominator = 8;
	}
    
	Fraction(const int &num_in, const int &den_in = 1)  // ������: Ŭ������ �̸��� ����
	{
		numerator = num_in;  
		denominator = den_in;
		cout << "Fraction() constructors, frac" << endl;
	}
	
	void print(){
		cout << numerator << " / " << denominator << endl;
	}
};

// Ŭ���� ������ ���� �ð� �ľ��ϱ� 
class Second
{
public:
	Second(){
		cout << "class Second ������ ����!" << endl;
	}
};

class First
{
	Second sec; // Ŭ���� �ȿ� ��ü ���� 
public:
	First(){
		cout << "class First ������ ����!" << endl;
	}
	
};

int main(){
	// �Ű����� �ִ� �����ڰ� �ֱ� ������ �⺻ ������ ȣ�� �Ұ���
	// �⺻ ������ ���� �ÿ� ��� ���� 
	Fraction f; 
	f.print();
	
	Fraction f2(1, 3); // �μ��� �� ����� �ʱ�ȭ
	f2.print();
	
	// ---------------------------------------------------------------------
	
	First fir; 
	/* <��� ���>
	class Second ������ ����!
	class First ������ ����!
	*/
	// First Ŭ������ ����� Second ��ü ����
	// Second Ŭ������ ������ �Լ� ���� 
	// First Ŭ������ ��� �غ�Ǿ����Ƿ�
	// First Ŭ���� ������ �Լ� ���� 
} 
