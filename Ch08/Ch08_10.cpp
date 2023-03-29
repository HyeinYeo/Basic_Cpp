#include <iostream>
using namespace std;

/* 정적(static) 멤버 변수 */
/* 
	- static 멤버 변수 
		- 모든 객체가 한 메모리를 공유하는 멤버 변수(모든 객체가 공유하는 멤버 변수)
			cf. python 클래스 변수 
			- 프로그램 시작때부터 메모리 차지
				- 프로그램 종료 때까지 메모리에 값 유지
				- 객체 생성 전에도 메모리 존재
				- 객체 생성 전, 초기화 필수 
			
			- 객체와 독립적으로 존재
			- 객체 이름, 클래스 이름으로도 접근 가능 
		
		1. 반드시 전역범위에서 초기화(정의) 
			<자료형> 클래스명::static변수 = 초기화값; 
		
			- 단순 선언은 실제 메모리를 사용하지 않기 때문
			- 정의는 실제 메모리 할당
			
			- 클래스 내: "선언"만 가능, 정의는 불가능
			- 전역범위: 정의 필수 
			
			- main 함수는 물론이고 생성자 안에서도 초기화 할 수 없음 
			
		2. 정의 및 초기화는 헤더 파일 내에서는 불가능
	
	- static const 멤버 변수
		1. 클래스 내에서 초기화 하는 것 가능
			- 값을 변경하는 것이 불가능하기 때문
			- 그 모습 그대로를 모든 객체가 공유
			
		2. 헤더파일 내에서도 초기화가 가능
			
	
	- private인 static 멤버 변수 초기화
		1. private하더라도 클래스 "외부"에서 정의가 가능!!!
			- static멤버는 클래스 내부에선 초기화가 불가능하므로
			
	- static 멤버 변수를 클래스 내부에서 초기화
		- inner-class를 사용
			- 클래스 안에 클래스를 하나 더 만들고 그 클래스의 생성자 안에서 초기화
			- 클래스에서 내부 클래스의 클래스 객체를 static 멤버 변수로 선언
			
 */
 
class Something
{
public:
	static int m_value; // 선언...
	static const int m_value2; // static const 가능!
};

int Something::m_value = 1; // 전역 범위에서 초기화


// private static 멤버 변수 초기화
class A
{
private:  
	static int s_value;
}; 

int A::s_value = 0; // 가능! 

// inner-class
class Something2
{
public:
	class _init // inner class
	{
	public:
		_init()
		{
			s_value = 9876; // s_value 접근 가능.
		}
	};

private:
	static int s_value; 
	static _init s_initializer; // 내부 클래스 객체를 static 멤버 변수로 선언
};
Something::_init Something::s_initializer; // 전역 범위에서 static 멤버 변수인 s_initializer를 정의

int main()
{
    // int Something::m_value = 1;  에러!!! 전역 범위에서만 가능. 

    cout << Something::m_value << endl;  // 1 출력, 객체 생성 전에도 사용 가능
    cout << &Something::m_value << endl;  // 0x472010 출력, 객체 생성 전에도 사용 가능

    Something st1;
    Something st2;

    st1.m_value = 2;

    cout << st1.m_value << endl;  // 2 출력 
    cout << &st1.m_value << endl; // 0x472010 출력

    cout << st2.m_value << endl;  // 2 출력
    cout << &st2.m_value << endl; // 0x472010 출력

    st2.m_value = 1024;

    cout << Something::m_value << endl; // 1024 출력
    
    
    // ---------------------------------------------------
    A a;
	cout << a.s_value << endl;

	//A::s_value = 1;  // 에러! private이므로 s_value 에 접근 불가능 

    return 0;
}
