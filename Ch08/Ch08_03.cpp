#include <iostream>
using namespace std;

/* 생성자 */

/*
	1. 생성자 
		- 객체가 메모리에 잡히자마자 실행되는 함수.
		- 객체가 생성되자마자 실행되는 함수
		- 주로 멤버들을 초기화하는 내용이 들어감
		

	2. 사용 방법 
		- ** 이름이 클래스의 이름과 같음 
		- ** 객체가 생성되자마자 실행되어야 하므로 public
			- private로 쓰는 경우도 있음 
		 
	3. 주의사항
		- 생성자 함수 매개변수 없을 때 객체 생성 시 꼭!! 괄호 뺌 
			- Fraction f; // Fraction 생성자 매개변수 없는 경우 
			- () 괄호는 매개변수 있는 생성자를 호출할 때만 사용 
		
		- 매개변수, 매개변수의 디폴트값 사용 가능 
		
		- 클래스 안에 생성자 정의가 아예 없을 때
			- 아무 일도 안하는 Fraction() {} 매개변수 없는 기본 생성자가 숨어 있음
			- Fraction frac; 객체를 생성하면 숨어있던 기본 생성자가 호출됨 
			- 매개변수를 가지고 있는 생성자가 하나라도 있으면,
			  매개변수가 없는 생성자는 없으므로 기본 생성자는 호출 불가능
			  
			- 기본 생성자 정의 시에도 매개변수 있는 생성자와 중복될 수 있기 때문에 사용에 주의 
			  	Fraction()   // 기본 생성자
			    {
					numerator = 5; 
					denominator = 8;
				}
			    
				Fraction(const int &num_in = 1, const int &den_in = 1)  // 충돌! 
				{
					numerator = num_in;  
					denominator = den_in;
				}
				
		- 복사 초기화(copy initialization) 
			Fraction f = Fraction{1, 3}; // 권장 X 
			  
	4. 생성자 호출시 ()와 {}의 차이
		- {}을 사용하여 호출하는게 더 엄격
		- 자동으로 형변환 해주지 않음
		Fraction 생성자에서 인수를 int로 받을 때, 
			Fraction frac{1.0, 3.0}; // 에러 O
			Fraction frac(1.0, 3.0); // 에러 X
		
		
*/

class Fraction
{
private:
	int numerator; // 분자
	int denominator; // 분모 
	
public:
	Fraction()   // 기본 생성자
    {
		numerator = 5; 
		denominator = 8;
	}
    
	Fraction(const int &num_in, const int &den_in = 1)  // 생성자: 클래스의 이름과 같음
	{
		numerator = num_in;  
		denominator = den_in;
		cout << "Fraction() constructors, frac" << endl;
	}
	
	void print(){
		cout << numerator << " / " << denominator << endl;
	}
};

// 클래스 생성자 실행 시간 파악하기 
class Second
{
public:
	Second(){
		cout << "class Second 생성자 실행!" << endl;
	}
};

class First
{
	Second sec; // 클래스 안에 객체 생성 
public:
	First(){
		cout << "class First 생성자 실행!" << endl;
	}
	
};

int main(){
	// 매개변수 있는 생성자가 있기 때문에 기본 생성자 호출 불가능
	// 기본 생성자 정의 시엔 사용 가능 
	Fraction f; 
	f.print();
	
	Fraction f2(1, 3); // 인수로 각 멤버를 초기화
	f2.print();
	
	// ---------------------------------------------------------------------
	
	First fir; 
	/* <출력 결과>
	class Second 생성자 실행!
	class First 생성자 실행!
	*/
	// First 클래스의 멤버인 Second 객체 생성
	// Second 클래스의 생성자 함수 실행 
	// First 클래스의 멤버 준비되었으므로
	// First 클래스 생성자 함수 실행 
} 
