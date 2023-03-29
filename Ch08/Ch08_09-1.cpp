#include <iostream>
using namespace std;

/*	클래스와 const */
/* 
	- const <클래스명> 객체
		- '객체의 멤버의 값을 바꿀 수 없다'
		- setter 접근 함수 사용 불가능
			- setter는 const 멤버 함수로 만들 수 없음 
		- getter 접근 함수의 사용도 불가능
		- 뒤에 const가 붙은 멤버 함수만 사용 가능
			- 멤버 함수가 const인가 아닌가로 판단
		- 함수에 인수로 객체를 넘길 때, 그 안에서 사용될 일이 있는 멤버 함수라면 뒤에 const를 붙여주어야 함 
		- const가 붙지 않은 일반 객체도 const멤버 함수를 호출할 수 있음 
 */
 
class Something{
	int m_value;
	
public:
	Something(){
		m_value = 0;
	}
	void setter(int value){
		m_value = value;
	}
	int getter() const{ // 함수 뒤에 const 붙이면 멤버변수를 수정하지 못하게 read-only로 만들겠다는 뜻 
		return m_value;
	}
 };
 
 
 int main(){
 	const Something s1;
 	Something s2;
 	
 	//s1.setter(1); // 불가능
	s2.setter(2); // 가능
	
	cout << s1.getter() << endl; // 가능
	cout << s2.getter() << endl; // 가능 
 } 
