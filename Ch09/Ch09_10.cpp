#include <iostream>
using namespace std;
/* ��ȯ ������ & explicit & delete */
/*	
	
	1. ��ȯ ������ 
		- �����ڸ� ��Ȯ�� ȣ���ϰ� ���� ���� ȣ����� ���� ���� ���
		- �⺻ �ڷ��� 1���� �μ��� �޴� �����ڴ� �����Ϸ��� �ڵ� ����ȯ 
		  �μ� Ÿ���� �߸� �Ѱ������� �����Ϸ��� �����ڸ� ȣ���Ͽ� Fraction Ÿ���� �ӽ� ��ü�� �ڵ� ����ȯ
		- �̷� ������ ����� ������ => ��ȯ ������
		
	2. explicit
		- ������ �տ� explicit ����
		- ��ȯ �������� ������ ȣ���� ���� ��Ȯ���� ������ 
		
	3. delete
		- �����ڿ� delete Ű���带 ����
		  �������Լ���(<�ڷ���>) = delete;
		   
		- Ư�� Ÿ���� �μ��� ���� �ʵ��� ���� 
		cf. ���� �޸� ���� delete�ʹ� �ٸ� 
		
*/
class Fraction
{
private:
	int m_numerator;
	int m_denominator; 

public:
	// delete Ű���� ���
	Fraction(char) = delete; // char Ÿ�� �μ� ���� ���ϵ��� ���� 
	
	// explicit Ű���� ��� 
	explicit Fraction(int num = 0, int den = 1) 
		: m_numerator(num), m_denominator(den)
	{
		assert(den != 0); 
	}
	
	Fraction(const Fraction &fraction)
		:m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{ 
		cout << "Copy constructor called" << endl; 
	}

	friend std::ostream & operator << (std::ostream & out, const Fraction & f)
	{
		out << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
	
};

void doSomething(Fraction frac)
{
	cout << frac << endl;
}

int main()
{	// ���� ���� 
	Fraction frac(7);
	doSomething(frac); // 7 / 1 ��� 
	
	// �͸� ��ü �̿� 
	doSomething(Fraction(7)); // 7 / 1 ��� 
	
	// ��ȯ ������ 
	doSomething(7); // 7 / 1 ���, 7�� ���� ��
	// 7�� �μ��� �Ѱ��� �� �Լ� ������ �Ű����� ��ü�� frac�� ����
	// Fraction frac = 7, �� Fraction(int num = 0, int den = 1) ������ ȣ�� 
	// ��Fracion(7, 1)���� ȣ���� ���̳� ���������� Fraction Ÿ���� �ӽð�ü ���� 
	
	// ==> �����ڿ� explicit Ű���� ���̸� ���� �߻�(���� ������)
	// 	   Ÿ���� ��Ȯ�� �ؼ� ȣ���ϵ��� �� 
	
	
	// delete
	Fraction frac2('c'); // ���� �߻�! 

	return 0;
}
