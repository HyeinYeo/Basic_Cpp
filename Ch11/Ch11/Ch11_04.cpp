#include <iostream>
using namespace std;
/* 유도된 클래스(Derived class) 생성 & 초기화 */
/*
	1. 클래스 크기
		- 자식 클래스는 물려받은 부모 클래스의 멤버도 포함 => 크기도 합쳐진 크기
		- 부모 클래스까지 포함한 큰 메모리 사이즈 할당 받음 
	
	2. 생성자 호출은 부모부터, 소멸자 호출은 자식부터
	 
*/

/* 1 - 1) int, int */
class Mother
{
    int m_i;
};

class Child : public Mother
{
    int m_d;
};

/* 1 - 2) int, double */
class Mother2
{
    int m_i;
};

class Child2 : public Mother 
{
    double m_d;
};

/* 2. */
class A
{
public:
	A(int a)
	{
		cout << "Constructor A"<< endl;
	}
	
	~A()
	{
		cout << "Destructor A " << endl;
	}
};

class B : public A
{
public:
	B(int a, double b)
		: A(a)
	{
		cout << "Constructor B" << endl;
	}

	~B()
	{
		cout << "Destructor B " << endl;
	}

};

class C : public B
{
public:
	C(int a, double b, char c)
		: B(a, b)
	{
		cout << "Constructor C" << endl;
	}

	~C()
	{
		cout << "Destructor C " << endl;
	}
};

int main()
{
    cout << sizeof(Mother) << endl;   // 4 출력  (int)
    cout << sizeof(Child) << endl;    // 8 출력  (int + int)  물려받은 m_i과 자신만의 m_d
    
    cout << sizeof(Mother2) << endl;   // 4 출력  (int)
    cout << sizeof(Child2) << endl;    // 16 출력  (int + double)  물려받은 m_i과 자신만의 m_d
    								  // padding 때문에 4 + 8 = 12가 아닌 4 (+ 4) + 8 = 16 출력 
    								  
    								  
    C c(1024, 3.14, 'a');
    /* 출력결과 
	Constructor A
	Constructor B
	Constructor C
	Destructor C
	Destructor B
	Destructor A
	*/
}
