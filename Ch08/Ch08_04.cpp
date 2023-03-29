#include <iostream>
using namespace std;

/* 생성자 멤버 초기화 목록 */

/*
	생성자 내부 {} 중괄호 처리가 시작되기 전에 초기화를 먼저 완료되는 멤버 목록
	생성자 이름 바로 아래 : 에서, 즉 생성자 내부 바깥에서 각 멤버들을 초기화 가능
	(), {} 모두 사용 가능 
	
	- 초기화 우선 순위 ???
		- 생성자 함수 초기화가 우선순위 높음!
		
		- 우선순위 1번: 객체의 메모리 할당과 동시에 진행
		- 우선순위 2번: 객체의 메모리 할당이 완료된 후 실행, 1번에 의해 초기화된 것들을 덮어 씌움 
		- 우선순위 3번: 실제 메모리에 할당하는 과정이 아닌 단지 클래스의 정의 
		
		 
	
*/

class ABC
{
private:
    int m_abc;

public:
    ABC(const int &m_abc_in)
        : m_abc(m_abc_in)
    { }
};

class Something
{
private: /* 실행순서 1*/
    int m_i = 100;
    double m_d = 7.2;
    char m_c = 'K';
    int m_arr[5] = {10, 20, 30, 40, 50};
    ABC abc{1234};   // 다른 클래스 타입의 객체를 멤버로 가질 때

public:
    Something()
    	// 생성자 멤버 초기화 목록 /* 실행순서 2*/ 
        : m_i{ 10 }, m_d{ 3.14 }, m_c{ 'a' }, 
		m_arr{ 1, 2, 3, 4, 5 }, 
		abc{ m_i - 1 }// ABC의 생성자를 불러와 ABC abc{9}; 으로 넘어가게 됨 
		
		// Something() 
			//: m_arr{} { } // 배열의 모든 멤버가 0 (NULL)으로 초기화
    
	{	/* 실행순서 3*/
        m_i = 3;
        m_d = 3.0f;
        m_c += 1;
    }
    
    void print() const{
		cout << m_i << " " << m_d << " " << m_c << endl;
	}
};

int main(){
	Something st;
	st.print();
	return 0;
}
