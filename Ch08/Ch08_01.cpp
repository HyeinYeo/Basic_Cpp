#include <iostream>
using namespace std;

/*객체지향 & 클래스*/

/*
	1. 클래스
		- 비슷한 데이터(멤버 변수), 기능(멤버 함수)들을 묶어 그룹화 한 것
		- 공통적인 데이터와 기능들을 모아 추상화 한 것
		- 아직 구체화 되어 메모리 상에 실존하는 것이 아니기 때문에 주소를 찍어볼 수 없음
		
		- 함수 사용 시 매개변수를 많이 넘겨줄 필요가 없음 
		
	2. 객체
	 	- 클래스를 틀로 찍어내어서 메모리 상에 실존하게 한 것
	 	- 객체마다 각각의 데이터 값은 모두 다름
		- 각 객체는 서로 독립적
		- 객체는 메모리 상에 실존하는 것이므로 메모리 주소를 찍어볼 수 있음 
		
	3. 클래스 vs. 구조체 
		- 클래스
			- 접근 지정자 가짐
				- public 
				- private
				- protected 
			-  데이터(멤버변수)와 기능(멤버함수)을 가짐 
			
		-  구조체
			- 주로 데이터(멤버 변수)만 넣음 
			
	cf. Java
		- Java 에선 객체 생성시 new 사용 
*/

class Friend
{
public:
	string _name;
	string _address;
	int _age;
	double _height;
	double _weight;

	void print() // 매개변수에 안 넣어도 됨 
	{
		cout << _name << " " << _address << " " << _age << " " << _height << " "
			<< _weight << endl;
	}
};


int main()
{
	Friend rachel; // 객체 생성 

    rachel.name = "Rachel";
    rachel.name = "Seoul";
    rachel.name = 2;
    rachel.name = 30;
    rachel.name = 10;


	rachel.print();   // 깔끔! 

	return 0;
}
