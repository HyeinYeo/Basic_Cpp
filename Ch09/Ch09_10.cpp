#include <iostream>
using namespace std;
/* 변환 생성자 & explicit & delete */
/*	
	
	1. 변환 생성자 
		- 생성자를 명확히 호출하고 쓸데 없는 호출들을 막기 위한 방법
		- 기본 자료형 1개를 인수로 받는 생성자는 컴파일러가 자동 형변환 
		  인수 타입이 잘못 넘겼음에도 컴파일러가 생성자를 호출하여 Fraction 타입의 임시 객체로 자동 형변환
		- 이런 현상이 생기는 생성자 => 변환 생성자
		
	2. explicit
		- 생성자 앞에 explicit 붙임
		- 변환 생성자의 무작위 호출을 막고 명확성을 높여줌 
		
	3. delete
		- 생성자에 delete 키워드를 붙임
		  생성자함수명(<자료형>) = delete;
		   
		- 특정 타입의 인수는 받지 않도록 막음 
		cf. 동적 메모리 해제 delete와는 다름 
		
*/
class Fraction
{
private:
	int m_numerator;
	int m_denominator; 

public:
	// delete 키워드 사용
	Fraction(char) = delete; // char 타입 인수 받지 못하도록 막음 
	
	// explicit 키워드 사용 
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
{	// 기존 사용법 
	Fraction frac(7);
	doSomething(frac); // 7 / 1 출력 
	
	// 익명 객체 이용 
	doSomething(Fraction(7)); // 7 / 1 출력 
	
	// 변환 생성자 
	doSomething(7); // 7 / 1 출력, 7만 들어가도 됨
	// 7이 인수로 넘겨질 때 함수 내부의 매개변수 객체인 frac이 생성
	// Fraction frac = 7, 즉 Fraction(int num = 0, int den = 1) 생성자 호출 
	// “Fracion(7, 1)”로 호출한 것이나 마찬가지인 Fraction 타입의 임시객체 생성 
	
	// ==> 생성자에 explicit 키워드 붙이면 오류 발생(문제 막아줌)
	// 	   타입을 명확히 해서 호출하도록 함 
	
	
	// delete
	Fraction frac2('c'); // 오류 발생! 

	return 0;
}
