#include <iostream>
#include <string>
using namespace std;
/* ��Ӱ� ��ü ������ */
/*
	1. ��ĳ����
		- �θ� Ŭ���� Ÿ�� �����ͷ� �ڽ� ��ü ������ ����ϱ�
			- �θ� Ŭ���� �����ʹ� �θ� Ŭ���� ������ public �κи� ���� ����
		- ����� Ÿ�� ��ȯ �ʿ� ����(���� ����)
		
	2. �ٿ� ĳ���� 
		- �ڽ� Ŭ���� Ÿ�� �����ͷ�, �ڽ� Ŭ���� Ÿ������ ĳ������ �θ� ��ü�� ������ ����ϱ� 
		- ����� Ÿ�� ��ȯ �ʿ�
		- (�θ�)��ü ������ ���� �Լ� ȣ���ϴ� ��� ����! -> ������ ������ ����(�� Ÿ�� ����) 
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
	// 1. ��ĳ����
	ColorPoint cp;
	ColorPoint *pDer = &cp;
	Point *pBase = pDer; // ��ĳ����: �θ�Ÿ�� �����Ͱ� �ڽ�Ÿ�԰�ü ����Ű����
	// Point *pBase = (Point*)pDer;���� ĳ���� ���� ���� 
	
	pDer->set(3, 4);
	pBase->showPoint(); // �θ� Ŭ������ �ִ� public ����Լ� ���� ����
	pDer->setColor("Red");
	pDer->showColorPoint();
	// pBase->showColorPoint(); // �ڽ� Ŭ������ ����Լ����� ���� �Ұ���!  
	
	// 2. �ٿ� ĳ����
	ColorPoint *pDer2;
	Point *pBase2, po;
	pBase2 = &po;
	pDer2 = (ColorPoint*)pBase2; // �ٿ� ĳ����
	pDer2->set(3, 4); // �θ� ��ü�� �ִ� �Լ��� ���� ���� 
	pDer2->setColor("Red"); // �θ� ��ü�� ���� �Լ��� ���� �Ұ���. �׷��� ������ ������ �� �� 
}
