#include <iostream>
#include <cassert>
using namespace std;
/* ���� ������ & ���� ���� & ���ϰ� ����ȭ*/
/*	
	
	1. ���� ������
		- � ��ü�� �����Ͽ� �Ȱ��� Ÿ���� ��ü�� ������ �� ���� �����ڰ� ȣ��� 
		
	2. ���� ����
		- �͸�ü�� �μ��� �� �� 
		- �Ϲ� �����ڸ� ȣ��, ���� ���� ����
		
		  Fraction fr_copy3(Fraction(3, 10));
		- fr_copy3 ��ü�� Fraction(3, 10)�� ����� ����
		
*/

class Fraction{
	private:
		int m_numer;
		int m_denom;
		
		/* ���� �����ڸ� private�� �ű�� ���� �Ұ���
		Fraction(const Fraction &fraction){ // �ڱ�� �Ȱ��� Ÿ���� �ν��Ͻ��� ��� ��, ������ ����� �μ��� ���� 
			m_numer = fraction.m_numer;
			m_denom = fraction.m_denom;
			cout << "���� ������ ȣ��" << endl;
		} 
		*/
		
	public:
		// ������
		Fraction(int numer, int denom){
			assert(denom != 0);
			m_numer = numer;
			m_denom = denom;
		} 
		// ���� ������
		Fraction(const Fraction &fraction){ // �ڱ�� �Ȱ��� Ÿ���� �ν��Ͻ��� ��� ��, ������ ����� �μ��� ���� 
			m_numer = fraction.m_numer;
			m_denom = fraction.m_denom;
			cout << "���� ������ ȣ��" << endl;
		}
		friend std::ostream& operator << (std::ostream &out, const Fraction &f)
		{
			out << f.m_numer << " / " << f.m_denom << endl;
			// cout ��� out 
		}
}; 

int main(){
	Fraction frac(3, 5);
	
	Fraction fr_copy(frac); // ���� ������ ȣ��!
	Fraction fr_copy2 = frac; // ���� ������ ȣ��!
	
	cout << frac << " " << fr_copy << " " << fr_copy2 << endl; // 3/5 3/5 3/5 ��� 
	
	
	// ������� ������ �� : �͸�ü�� �μ��� �� ��
	Fraction fr_copy3(Fraction(3, 10)); //  �Ϲ� �����ڸ� ȣ��, ���� ���� ����
	// fr_copy3 ��ü�� Fraction(3, 10)�� ����� ���� 
	return 0; 
}
