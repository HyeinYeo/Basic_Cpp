#include <iostream>
using namespace std;
/* 입출력 연산자 오버로딩 */
/*	
	** 입출력 연산자는 "전역 함수"로만 구현
	   멤버함수로 구현 불가능 
	
	1. 출력 연산자 오버로딩 
	friend std::ostream& operator << (std::ostream &out, const Point &point)
	
	2. 입력 연산자 오버로딩 
	friend std::istream& operator >> (std::istream &in, Point &point)
*/

class Point{
	double m_x, m_y, m_z;
	
public:
	Point(double x = 0, double y = 0, double z = 0){
		m_x = x; m_y = y; m_z = z;
	}
	
	// 출력 연산자 << 오버로딩 
	friend std::ostream& operator << (std::ostream &out, const Point &point)
	{
		out << point.m_x << " " << point.m_y << " " << point.m_z << endl;
		// cout 대신 out 
		
		return out; // 체이닝 가능 
	}
	// 입력 연산자 >> 오버로딩
	friend std::istream& operator >> (std::istream &in, Point &point){
		in >> point.m_x >> point.m_y >> point.m_z;
		
		return in;
	}
};

int main(){
	Point p1(1.0, 2.0, 10.0);
	Point p2(5.7, 2.2, 3.8);
	
	cout << p1 << p2 << endl;
	
	
	Point p3, p4;
	cin >> p3 >> p4;
	cout << p3 << p4 << endl;
	
} 
