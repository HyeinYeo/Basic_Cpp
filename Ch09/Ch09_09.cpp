#include <iostream>
#include <cassert>
using namespace std;
/* 복사 생성자 & 복사 생략 & 리턴값 최적화*/
/*	
	
	1. 복사 생성자
		- 어떤 객체를 복사하여 똑같은 타입의 객체를 생성할 때 복사 생성자가 호출됨 
		
	2. 복사 생략
		- 익명객체가 인수로 들어갈 때 
		- 일반 생성자만 호출, 복사 과정 생략
		
		  Fraction fr_copy3(Fraction(3, 10));
		- fr_copy3 자체를 Fraction(3, 10)로 만들어 버림
		
*/

class Fraction{
	private:
		int m_numer;
		int m_denom;
		
		/* 복사 생성자를 private로 옮기면 복사 불가능
		Fraction(const Fraction &fraction){ // 자기와 똑같은 타입의 인스턴스가 들어 옴, 복사할 대상을 인수로 받음 
			m_numer = fraction.m_numer;
			m_denom = fraction.m_denom;
			cout << "복사 생성자 호출" << endl;
		} 
		*/
		
	public:
		// 생성자
		Fraction(int numer, int denom){
			assert(denom != 0);
			m_numer = numer;
			m_denom = denom;
		} 
		// 복사 생성자
		Fraction(const Fraction &fraction){ // 자기와 똑같은 타입의 인스턴스가 들어 옴, 복사할 대상을 인수로 받음 
			m_numer = fraction.m_numer;
			m_denom = fraction.m_denom;
			cout << "복사 생성자 호출" << endl;
		}
		friend std::ostream& operator << (std::ostream &out, const Fraction &f)
		{
			out << f.m_numer << " / " << f.m_denom << endl;
			// cout 대신 out 
		}
}; 

int main(){
	Fraction frac(3, 5);
	
	Fraction fr_copy(frac); // 복사 생성자 호출!
	Fraction fr_copy2 = frac; // 복사 생성자 호출!
	
	cout << frac << " " << fr_copy << " " << fr_copy2 << endl; // 3/5 3/5 3/5 출력 
	
	
	// 복사과정 생략될 때 : 익명객체가 인수로 들어갈 때
	Fraction fr_copy3(Fraction(3, 10)); //  일반 생성자만 호출, 복사 과정 생략
	// fr_copy3 자체를 Fraction(3, 10)로 만들어 버림 
	return 0; 
}
