#include <iostream>
using namespace std;
/* 산술 연산자 오버로딩 */
/*
	산술 연산자 오버로딩
		<리턴타입> operator 연산자 (매개변수)
		
		- 연산자에 특정 타입의 객체가 피연산자로 들어올 시 어떤 행동을 하게끔 미리 정의
*/

 
class Cents{
	int m_cents; 
	
public:
	Cents(int cents){
		m_cents = cents;
	} 
	int getter() const {
		return m_cents;
	}
	
	// 멤버 함수 오버로딩
	int operator + (const Cents &c1){
		return m_cents + c1.m_cents; // this->m_cents + c1.m_cents
	} 
	
	// 전역 함수 오버로딩 사용 시 접근하려는 멤버가 private일 때
	friend int operator + (const Cents &c1, const Cents &c2); 
};

// 전역 함수 오버로딩 
int operator + (const Cents &c1, const Cents &c2){
		return c1.m_cents + c2.m_cents;
}

int main(){
	Cents c1(6);
	Cents c2(8);
	cout << c1.getter() + c2.getter() << endl;
	
	cout << c1 + c2 << endl;
	// c1.+(c2);로 변환되어 전달됨
	// +가 함수명이라고 생각해보자 ex. c1.plus(c2); 느낌인 것! 
	
	return 0;
}
