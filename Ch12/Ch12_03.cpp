#include <iostream>
#include <typeinfo> 
using namespace std;
/* 가상함수: override, final, 공변 변환형 */
/*	
	1. override
		- 리턴타입 + 함수이름 + 매개변수 형태 + const 유무까지 똑같아야 함
		- 다르면? 오버라이딩이 아니라 오버로딩이 됨
		
		- override 키워드
			- 오버라이딩 한 함수라고 강조
			- 오버라이딩이 제대로 안됐을시 컴파일 에러 발생
			
	2. final
		1) 자식 클래스에서 오버라이딩을 못하도록 막아버림
		2) 클래스 전체가 상속되지 못하게 막아버림 
		
	3. 공변 반환형
		 - 리턴 타입이 다른데도 오버라이딩이 되는 경우
		   ==> this (자기 자신을 가리키는 포인터)을 리턴하는 함수의 경우
		       A 와 B 가 부모 자식 관계이기 때문
		 
*/

class A
{
public:
    virtual void print(int x) { cout << "A" << endl; }
    
    virtual void print2(int x) { cout << "AA" << endl; }
    
    // 3. 공변 반환형
	virtual A* getThis() 
    { 
		cout << "A::getThis()" << endl;
		return this; 
    }
    void print3() { cout << "AAA" << endl; }
};


class B : public A
{
public:
	// 1. override 키워드
    void print(int x) override { cout << "B" << endl; } 
    
    // 2. final 키워드 
    //	- 오버라이딩은 B 클래스까지가 마지막, 그 이후 자식 클래스부터는 이 함수 오버라이딩 불가능 
    void print2(int x) final { cout << "BB" << endl; }
    
    virtual B* getThis() // 반환타입 다른데도 오버라이딩 허용(this 반환하므로) 
    { 
		cout << "B::getThis()" << endl;
		return this; 
    }
    void print3() { cout << "BBB" << endl; }
};

class C : public B
{
public:
    // void print2()  { cout << "CC" << endl; }  // 에러 발생 
};


int main()
{
	// 3. 공변 반환형 
	A a;
	B b;

	A &ref = b;
	b.getThis()->print3();
	/* 출력 결과
		B::getThis()
		BBB
		
		B의 getThis() 호출, b.getThis()에서 B* 반환 
	*/
	ref.getThis()->print3(); 
	/* 출력 결과 
		B::getThis()
		AAA
		
		B의 getThis()를 호출해서 this를 리턴,
		this는 참조변수 타입인 A로 변환됨
		A의 print3() 호출 
	*/ 

	cout << typeid(b.getThis()).name() << endl;  // class B* 출력
	cout << typeid(ref.getThis()).name() << endl; // class A* 출력

	return 0;
}
