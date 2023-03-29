#include <iostream>
using namespace std;

/* 소멸자 */

/*	
	1. 소멸자 
		- 객체가 영역을 벗어나서 메모리에서 해제될 떄 "자동으로" 호출되는 함수 
			cf. 생성자: 객체가 메모리를 차지할 때, 즉 객체가 생성될 때 프로그래머가 직접 호출하는 함수
			
		- 인스턴스가 메모리에서 해제될 때, 내부에서 자동으로 호출
			- 동적할당(new)으로 만들어진 경우는 자동으로 메모리 해제 X
			- delete로 매모리 해제할 때만 소멸자 호출 
	
	2. 호출 과정 : ~ 클래스이름()
		- 소멸자는 인수를 받지 않음. 매개 변수 없음.
		- 자동으로 호출되는 함수이며 프로그래머가 직접 호출하는건 권장하지 않음
	
		- 객체가 속한 영역이 종료될 때 메모리가 반납 되면서 소멸자 호출 
		- ** 가장 나중에 만들어진 객체가 먼저 사라짐 
			- 스택 메모리를 사용하므로 가장 나중에 만들어진 객체가 가장 먼저 삭제
			
	3. 활용
		- 메모리 누수 방지
			- 메모리를 동적 할당 받는 멤버가 있을 때 소멸자 안에서 이 멤버를 delete 해주면 메모리 누수 방지
	
	
*/
class Simple
{
private:
	int m_id;

public:
	Simple(const int& id_in)
		: m_id(id_in)
	{
		cout << "constructor" << m_id << endl;
	}

	~Simple()  // 소멸자
	{
		cout << "Destructor" << m_id << endl;
	}
};

// 활용(동적할당 해제)
class IntArray
{
private:
	int *m_arr = nullptr;
	int m_length = 0;
	
public:
	IntArray(const int& length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];  // m_arr 멤버는 동적할당 받고 있다.

		cout << "constructor" << endl;
	}

    ~IntArray()
    {
		if (m_arr != nullptr) 
        	delete [] m_arr;  // 객체 소멸시 m_arr 멤버는 해제해주기!
    }

	int getLength() {return m_length;}
	
}; 

int main()
{
	Simple s1(0);  // 생성자 호출, m_id = 0
	Simple s2(1);  // 생성자 호출, m_id = 1
	

	//return 0;  // 영역을 벗어나면서 두 객체 모두 소멸자 호출
	
	/* 출력 결과 
	constructor0
	constructor1
	Destructor1 // 1번 객체가 먼저 소멸자 호출됨 
	Destructor0
	*/
	
	// -------------------------------------------------------
	while (true) 
	{
		IntArray my_int_arr(10000);
	}
	// return 0;
	/*
	- 객체 생성시 m_arr 멤버는 메모리를 동적으로 할당받음
	- delete 안 하는 경우 -> 객체를 무한으로 생성하므로 메모리 누수 발생
	- 소멸자에 m_arr 멤버를 delete 코드 포함 
		->  while문 안에서 다음 반복으로 넘어갈 때마다 객체가 소멸(소멸자 호출)
	
	
	return 0;
}
