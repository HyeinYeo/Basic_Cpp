#include <iostream>
using namespace std;

/* 정적(static) 멤버 함수 */
/* 
	1. static 멤버 함수 
		- 객체 이름은 물론이고 클래스 이름만으로도 접근 가능
		- 객체와 독립적
	2. static 멤버 함수 내 -> 일반 멤버 변수를 사용할 수 없음
		- why? 일반 멤버 변수는 객체 생성되어야 메모리 할당받기 때문
		
	3. static 멤버 변수는 사용 가능
		- why? 미리 전역에서 메모리가 할당되기 때문 
		
	4. static 멤버 함수 내 -> this 포인터 사용 불가능
		- why?  this 포인터는 객체인 자기 자신의 주소, 즉 객체의 주소를 담고 있기 때문에 객체가 생성되어야지만 사용할 수 있음
		- this포인터로 접근할 수 있는 모든 것을 하지 못함 
		
	** 멤버함수
	-  일반 함수는 함수 이름에 함수의 주소값이 들어있음
	-  멤버 함수의 포인터는 &클래스이름::함수이름 으로 접근!
		
		Something s;

		int (Something::*fptr_1)() = &Something::temp; // s.temp라고 하면 안 됨 
		cout << (s.*fptr_1)() << endl;
	
		- 멤버 "변수"는 각 객체들마다 따로 메모리를 가져 주소가 다름 
		- BUT!
		- 멤버 "함수"는 어딘가 한 군데에 저장되어 있고,
		  각 객체마다 그 공간에 동일하게 접근하여 각자의 다른 데이터로 사용하는 방식
	- 함수 포인터로 일반 멤버 함수를 실행할 때는 꼭 (s.*fptr_1)() 처럼 객체로 접근해 주어야 함(s. 필수라는 말) 
	
	- static 멤버 함수
		
		Something s;

		int (*fptr_2)() = &Something::temp;
		cout << fptr_2() << endl;
		
		- 객체와 무관하게 연산이 이루어 지기 때문에 "일반 함수 포인터"로 취급
		- 포인터 선언시 클래스이름을 떼고 일반 함수처럼 int (*fptr_2)()로만 선언
		- 단독 호출 가능(s. 없어도 됨) 
	
	
*/

class Something{
	int normal = 10; // 일반 멤버 변수
	static int s_value; // static 멤버 변수 선언
	// 직접 접근 불가능 
	
public:
	static int getter(){ // static 멤버 함수 
		// cout << normal << endl; // 일반 멤변은 사용 불가능
		// this -> s_value; // this 포인터 사용 불가능 
		return s_value; // static 멤버 변수는 사용 가능 
	} 
};
int Something::s_value = 0; // static 멤버변수 초기화(정의) 

int main(){
	
	cout << Something::getter() << endl; // 객체 생성 전에도 사용 가능 
}
