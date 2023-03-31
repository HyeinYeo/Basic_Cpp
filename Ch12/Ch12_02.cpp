#include <iostream>
using namespace std;
/* 가상함수 & 다형성 */
/*	
	- 참조하거나 가리키는 객체의 타입이 아니라, 참조하는 변수 혹은 포인터의 타입이 무엇이냐에 따라 멤버 호출
	  B b;
	  A &ref1 = b;
	  ref1.print();
	  	- B타입 객체인 b를 참조하고 있더라도, ref1은 A타입이기 때문에 ref1.print(); A의 print() 호출
	  
	- virtual
		- 참조하는 객체의 타입이 무엇이냐에 따라 호출
			- 부모 포인터로 호출하더라도, 자식이 오버라이딩한 함수 호출
		- 조상 클래스 virtual 가상 함수는 대대손손 유지
			- 재상속 거쳐도 자식 클래스에서 virtual을 붙여 주지 않더라도 그대로 가상함수 특성 유지
	
	- 동적 바인딩
		- 가상함수 호출 시, 실행 중에 자식 클래스 객체 내에 오버라이딩된 가상함수를 동적으로 찾아 호출
		- 자식 클래스 객체에 대해, 부모 클래스 포인터로 가상함수 호출될 때 동적 바인딩
		* 동적 바인딩 발생하는 경우
			- 부모 클래스 내의 멤버함수가 가상함수 호출 
			- 자식 클래스 내의 멤버함수가 가상함수 호출
			- main()과 같은 외부함수에서, 부모클래스의 포인터로 가상함수 호출
			- 다른 클래스에서 가상함수 호출			
	**  "오버라이딩" : 리턴까입까지도 같아야 함 
	 
*/
class A
{
public:
	// void print() { cout << "A" << endl; }
	virtual void print() { cout << "A" << endl; }
}; 

class B : public A
{
public:
	void print() { cout << "B" << endl; }
};

class C : public B
{
public:
	void print() { cout << "C" << endl; }
};

class D : public C
{
public:
	void print() { cout << "D" << endl; }
};

int main()
{
	A a;
	B b;
	C c;
	D d;

    A &ref1 = b;
    ref1.print();
    // virtual 전: A 출력
    // virtual 후: B 출력 

	C &ref2 = d;
	ref2.print();
	// virtual 전: C 출력
    // virtual 후: D 출력 

	return 0;
}
