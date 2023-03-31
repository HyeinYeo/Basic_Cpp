#include <iostream>
using namespace std;
/* 가상함수: 가상 소멸자 */
/*	
	1. 일반적 소멸자
		- 생성자 호출 순서: 조상 >> 자손
		- 소멸자 호출 순서: 자손 >> 조상 
		
	2. 가상 소멸자
		- Derived의 소멸자 ~Derived()도 virtual 속성을 물려받게 됨 
		** 부모 소멸자가 가상 소멸자가 아니라면 자식 소멸자에 override를 붙일 수 없음
		
	** 생성자는 가상함수 될 수 없음
		생성자에서 가상함수 호출해도 동적 바인딩 X(자식 클래스가 적재(초기화) 전이라서 오버라이딩된 가상함수 인식 불가) 
		 
*/

/* 가상 소멸자 사용 전 */
class Base
{
public:
	~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int *m_array; 

public:
	Derived(int length)
	{
		m_array = new int[length];
	}

	~Derived()  
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};

/* 가상 소멸자 사용 후*/
class Base2
{
public:
	virtual ~Base2() // 소멸자 앞에 virtual 키워드 붙이기 
	{
		cout << "~Base2()" << endl;
	}
};

class Derived2 : public Base2
{
private:
	int *m_array; 

public:
	Derived2(int length)
	{
		m_array = new int[length];
	}

	~Derived2() override // 부모 소멸자가 가상 소멸자가 아니라면 자식 소멸자에 override를 붙일 수 없음 
	{
		cout << "~Derived2()" << endl;
		delete[] m_array;
	}
};

int main()
{
	// 기존 소멸자 
	// Derived derived(5); // ~Derived() ~Base() 호출 
	
	// 문제점
	Derived *derived1 = new Derived(5); // 동적 할당
    Base *base1 = derived1;  // 다형성, 동적할당
    delete base1; // ~Base() 출력 
    // => Derived 소멸자는 호출 되지 않고 부모인 Base 소멸자만 호출
    // 부모를 지우면 부모 소멸자만 호출되며 자식 소멸자는 호출되지 않음
	// 메모리 누수 문제 발생 가능
	
	
	// 가상 소멸자
	Derived2 *derived2 = new Derived2(5); // 동적 할당
    Base2 *base2 = derived2;  // 다형성, 동적할당
    delete base2; 
    /* 출력 결과 
		~Derived2()
		~Base2()
	*/

	return 0;
}
