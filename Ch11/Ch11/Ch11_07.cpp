#include <iostream>
using namespace std; 
/* 상속 함수 재정의 */
/*
	- virtual 키워드가 없는 상태로 오버라이딩 하는 경우
		- 포인터의 자료형(부모클래스 자료형 VS. 자식클래스 자료형)에 따라서 함수가 호출됨
		- 컴파일 타임, 정적 바인딩 
		
	<-> 가상함수 오버라이딩
		- 업 캐스팅한 포인터(부모클래스 자료형 포인터에 자식 객체 연결)
		- 자식 객체에 virtual 오버라이딩된 함수를 실행
		- 런 타임, 동적 바인딩  
*/

class Base{
public:
	void f(){ cout << "Base::f() called" << endl; }
};
class Derived : public Base{
public:
	void f(){ cout << "Derived::f() called" << endl; }
};

int main(){
	Derived d, *pDer; // '자식클래스 자료형 포인터'에 자식 객체 연결 
	pDer = &d;
	pDer->f(); // 자식클래스에 재정의된 함수 호출
	
	Base *pBase = pDer; // '부모클래스 자료형 포인터'에 자식 객체 연결(업 캐스팅) 
	pBase->f(); // 부모클래스에 정의된 함수 호출 
	
	/* 실행 결과 
		Derived::f() called
		Base::f() called
	*/
}


