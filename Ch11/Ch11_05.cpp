#include <iostream>
using namespace std;
/* 유도된 클래스(Derived class) 생성 & 초기화 */
/*
	1. public 상속
		- protected, public -> 접근 지정 변경 없이 자식 클래스에 그대로 상속 확장 
		 
	
	2. protected 상속
		- 모든 자식, 손자 클래스들 안에선 멤버를 사용할 수 있고 외부에서만 사용할 수 없음
		- private멤버는 모든 자식, 손자 클래스들 안에서도 접근 불가능
		- protected, public -> 모두 protected 접근 지정으로 변경되어 자식 클래스에 상속 확장
		
	3. private 상속
		- private으로 상속 받으면 마치 "자식 클래스 멤버 전체가 private화" 됨
		- 손자 클래스, 즉 재상속이 일어나면 모든 멤버에 접근하지 못함
			- 함수를 통해서 접근해야 함 
		- 직속 자식 클래스에서만 접근 가능
		- protected, public -> 모두 private 접근 지정으로 변경되어 자식 클래스에 상속 확장

	** 접근 지정자 생략 시 private로 자동 처리 
	 
*/


class Mother
{
public:
    int m_public;
protected:
    int m_protected;
private:
    int m_private;
};

/* 1. public 상속 */
class Daughter : public Mother
{
public:
    Daughter()
    {
        m_public = 7;    // 가능 
        m_protected = 7; // 가능 
        // m_private = 7;  // 불가능 
    }
};

/* 2. protected 상속 */
class Son : protected Mother
{
public:
    Son()
    {
        m_public = 7;    // 가능 
        m_protected = 7; // 가능 
        // m_private = 7;  // 불가능 
    }
};

/* 3. private 상속 */
class Daughter2 : private Mother // 재상속 막겠다는 것 
{
public:
    Daughter2()
    {
        m_public = 7;    // 가능 
        m_protected = 7; // 가능 
        // m_private = 7;  // 불가능 
    }
};

class GrandDaughter : public Daughter2
{
public:
    GrandDaughter()
    {
        // m_public = 24;  // 불가능
		// m_protected = 24; // 불가능 
        // m_private = 24;  // 불가능 
    }
};

int main()
{
	/* 1. public 상속 */
    Daughter daughter;
    daughter.m_public = 100;     // 가능 
    // daughter.m_protected = 100;  // 불가능
    // daughter.m_private = 100;  // 불가능 
    
    
    /* 2. protected 상속 */
    Son son;
    // son.m_public = 100; // 불가능 
    // son.m_protected = 100; // 불가능 
    // son.m_private = 100; // 불가능 
    
    
    /* 3. private 상속 */
    Daughter2 d2;
    // d2.m_public = 100;     // 불가능 
    // d2.m_protected = 100;  // 불가능
    // d2.m_private = 100;  // 불가능
}
