#include <iostream>
using namespace std;
/* 가상함수: 가상함수표 */
/*	
	- virtual 가상 함수 선언: 가상 함수 표를 만들고 동적 바인딩
		- 클래스는 가상함수표에 대한 포인터를 갖게 됨
		1) 가상 함수 포인터 *_vptr 를 보고 가상 함수표를 찾아간다.
		2) 가상 함수표에서 가상 함수인 fun1, fun2의 포인터를 받아온다. 
		3) 받아 온 주소를 통해 fun1, fun2 를 실행
		
		- 자식 클래스에도 가상함수표 포인터 상속
		1) 상속 받은 가상 함수 포인터 *_vptr 를 보고 가상 함수표를 찾아간다.
		2) 가상 함수표에서 가상 함수인 Base 클래스의 fun1, fun2의 포인터를 받아 온서 돌아온다.
		3) fun1 은 오버라이딩이 되어 있으므로 포인터를 통해 찾아가지 않고 본인이 "오버라이딩 한 fun1"을 실행
		   fun2 은 가상 함수표에서 찾아 온 Base의 fun2 주소를 보고 fun2를 실행한다.
		   
		- 가상 함수를 가지는 클래스는 가상 함수 포인터를 추가로 가지기 때문에 클래스 용량이 더 큼 
		 
*/

class Base{
public:
	// FunctionPointer *_vptr
	virtual void func1() {};
	virtual void func2() {};
};

class Derived : public Base{
public:
	// FunctionPointer *_vptr
	virtual void func1() {};
	void func3() {};
};
