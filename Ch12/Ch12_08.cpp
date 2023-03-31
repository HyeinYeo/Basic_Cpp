#include <iostream>
using namespace std;
/* 가상 기본 클래스, 다이아몬드 상속 문제 */
/*	
	1. 다중 상속
		- 두 개 이상의 클래스를 동시에 상속 받기 가능
			- 부모 클래스들의 기능을 (private 제외) 모두 사용 가능
	
	2. 다중 상속 모호성 문제
		부모 - 자식 1, 자식 2 - 손자 클래스 있을 때,
		- 부모 클래스의 멤버가 중복하여 공간을 차지하여, 손자 클래스 객체에서 그 멤버에 접근할 경우 모호함 발생 -> 컴파일 오류 
		
	3. 가상 상속 virtual
		- 다중상속 모호함 문제 해결 방법 
		- 자식 클래스 객체 생성 시, 이미 공간을 할당 받은 부모 클래스의 멤버에 대해 공간 할당을 하지 않도록 하는 지시
		- 자식 클래스 상속 시 virtual 선언해주면 됨 
		- 동적 바인딩 
*/
