#include <iostream>
#include <string>
using namespace std;
/* 유도된 클래스(Derived class) 생성 순서 */
/*
	1. 부모로부터 상속 받은 건 온전히 자기 자신의 것
		- 부모로부터 상속 받은 멤버들은 자기 자신의 멤버들이 됨
			m_i
			this -> m_i
			Mother::m_i = 1024
			this -> Mother::m_i = 1024
		- 단, Mother::멤버함수() => 오버라이딩 자식함수 X, 부모함수임
		
	2. 부모 생성자는 자식 생성자보다 무조건 먼저 호출
		- 무조건 부모 생성자 먼저 호출 
		- A (할머니) >> B(엄마) >> C(자식) 순으로 상속 시,
		  A 생성자 >> B 생성자 >> C 생성자 순 호출 
		
		- 단순히 메모리를 할당하는 것과 초기화하는 것 구분
			- 메모리 할당만: 쓰레기값 들어있음
			- 초기화: 할당 받은 메모리 공간에 원하는 값이 들어감 
		- 메모리는 자식이 먼저 할당받을 수도 있지만, 초기화에서만큼은 무조건 부모 멤버들이 먼저 초기화
*/
class Mother
{
public:
    int m_i;
    
    Mother()
        : m_i(0)
    {
        cout << "Mother construction" << endl;
	}
    
};


class Child : public Mother
{
public:
	double m_d;
	
    Child()
    	: Mother(), m_d(1.0) // Mother()가 제일 앞에 숨어있는 것! => 항상 먼저 실행 
    {
    	cout << "Child construction" << endl;
    	
    	// 1. 부모로부터 상속 받은 멤버들은 자기 자신의 멤버
    	// ** Mother에서 m_i가 public이기 때문에 이렇게 가능
		m_i = 0;
		Mother::m_i = 5; 
        this -> m_i = 10;
        this -> Mother::m_i = 1024;
        
        cout << this -> m_i << endl;
		cout << this -> Mother::m_i << endl; 
    }
};

int main(){
	// 2. 생성자 호출 순서: 부모 >> 자식
	Child c;
	/* 출력 결과 */
	// Mother construction
	// Child construction

    return 0; 
} 
