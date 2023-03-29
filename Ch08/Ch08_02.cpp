#include <iostream>
using namespace std;

/* 캡슐화 & 접근 지정자 & 접근 함수 */

/*
	1. 캡슐화
		- 외부로부터 중요한 데이터와 기능을 보호하고 은닉
		- 데이터와 기능들 중에서 접근할 수 있는 영역을 제한하고 외부로부터 은닉하는 것
		
		- 장점
			-  클래스 내의 멤버 변수 이름을 바꿔야 할 일이 생긴다면 
			   해당 멤버를 직접 접근하여 사용한 부분들도 다 이름을 바꿔줘야 함
			-  캡슐화 사용 시 멤버 변수명을 바꿔야 할 때도 그냥 클래스 내부에서만 바꾸어 주면 됨 
		
	2. 접근 지정자 
		** 명시 X -> 기본값 private
		 
		- public : 외부의 모든 곳에서 접근 허용
		
		- private: 클래스 내 멤버 함수로만 접근 가능
			- 접근함수 setter / getter
				- public한 접근 함수들을 만들어 이를 통해 간접적으로 접근
				
			- 서로 다른 별개의 객체더라도 클래스 타입이 동일하다면 각 멤버는 서로의 private 멤버 변수에 접근 가능
				- 접근 지정자의 접근 제어 기준은 클래스 기준(그때 그때 생성된 인스턴스의 기준이 아님)
		
		- protected: 클래스 내 멤버 함수 + 상속 받는 자식 클래스의 멤버 함수 접근 가능 
		
*/

class Date
{
	int m_year; // private, 외부에서 직접 값을 수정할 수 없음
	int m_month;
	int m_day;
	
public:
	int x; // 외부에서 값 수정 가능 
	
	// 접근 함수 
	void setter(const int &year_input, const int &month_input, const int &day_input){
		m_year = year_input;
		m_month = month_input;
		m_day = day_input;
	}
	
	const int& getterYear() {
		return m_year;
	}
	
	// 클래스 타입이 동일하다면 각 멤버는 서로의 private 멤버 변수에 접근 가능
	void copyFrom(const Date& origin){
		m_year = origin.m_year;
		m_month = origin.m_month;
		m_day = origin.m_day;
	} 
	
};

int main(){
	Date today; 
	today.setter(2022, 8, 15);
	cout << today.getterYear() << endl;  // 2022 출력, m_year 멤버를 리턴 받는다.
	
	Date original;
	original.setter(2002, 4, 1);
	today.copyFrom(original);
	cout << today.getterYear() << endl; // 2002 출력 

	return 0;
}
