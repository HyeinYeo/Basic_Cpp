#include <iostream>
#include <string>
using namespace std;
/* 상속과 객체 포인터 */
/*
	1. 업캐스팅
		- 부모 클래스 타입 포인터로 자식 객체 가리켜 사용하기
			- 부모 클래스 포인터는 부모 클래스 영역의 public 부분만 접근 가능
		- 명시적 타입 변환 필요 없음(생략 가능)
		
	2. 다운 캐스팅 
		- 자식 클래스 타입 포인터로, 자식 클래스 타입으로 캐스팅한 부모 객체를 가리켜 사용하기 
		- 명시적 타입 변환 필요
		- (부모)객체 공간에 없는 함수 호출하는 경우 주의! -> 컴파일 오류는 없음(런 타임 오류) 
*/

class Point{
	int x, y;
public:
	void set(int x, int y){ this->x = x; this->y = y; }
	void showPoint(){
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point{
	string color;
public:
	void setColor(string color){ this->color = color; }
	void showColorPoint(){
		cout << color << ":";
		showPoint();
	}
};

int main(){
	// 1. 업캐스팅
	ColorPoint cp;
	ColorPoint *pDer = &cp;
	Point *pBase = pDer; // 업캐스팅: 부모타입 포인터가 자식타입객체 가리키도록
	// Point *pBase = (Point*)pDer;에서 캐스팅 생략 가능 
	
	pDer->set(3, 4);
	pBase->showPoint(); // 부모 클래스에 있는 public 멤버함수 실행 가능
	pDer->setColor("Red");
	pDer->showColorPoint();
	// pBase->showColorPoint(); // 자식 클래스의 멤버함수에는 접근 불가능!  
	
	// 2. 다운 캐스팅
	ColorPoint *pDer2;
	Point *pBase2, po;
	pBase2 = &po;
	pDer2 = (ColorPoint*)pBase2; // 다운 캐스팅
	pDer2->set(3, 4); // 부모 객체에 있는 함수는 실행 가능 
	pDer2->setColor("Red"); // 부모 객체에 없는 함수는 실행 불가능. 그러나 컴파일 오류는 안 남 
}
