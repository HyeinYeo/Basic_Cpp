#include <iostream>
#include <cassert>
using namespace std;
/* 깊은 복사 & 얕은 복사 */
/*	
	1. 얕은 복사
		- 포인터 값인 주소만 복사하여 넘겨주는 것
		- 문제 발생 가능
		 
	2. 깊은 복사
		- 새로운 메모리를 할당받아 확보한 뒤 그 공간에 내용물만 복사해 오는 것
		
	3. 복사 생성자 vs 대입 연산자 오버로딩
		- 복사 생성자
			- 생성자이므로 객체가 생성되는 과정에서 대입이 있는 경우 호출
			 MyString str1("Hello");

			 MyString str2(str1);  // 복사 생성자 호출
			 Mystring str3 = str1; // 복사 생성자 호출
		
		- 대입 연산자 오버로딩 
			- 단순히 이미 존재하는 객체끼리의 대입 시 호출 
			- 자기 자신의 기존 동적 메모리를 비워주는 과정 필요
				- why? 자기 자신에게 다른 객체를 복사하여 덮어 씌우는 것이므로 
			 MyString str1("Hello");
			 MyString str2;  
			 // 이미 생성된 객체 str1, str2 
			 str2 = str1;  // 대입 연산자 오버로딩 호출
		
		
*/

class MyString
{
public:
	char *m_data = nullptr; 
	int m_length = 0;

	MyString(const char *source = "") 
	{
		assert(source);  // 문자열 인수로 꼭 받아야 함!

		m_length = std::strlen(source) + 1; 
		m_data = new char[m_length]; 
	
		for (int i = 0; i < m_length; ++i) 
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0'; // 문자열 마지막에 널 문자 붙여줌 
	}
	
	// 복사 생성자 : 깊은 복사 구현
	MyString(const MyString &source) 
	{
		m_length = source.m_length; 
	
		if (source.m_data != nullptr) 
		{
			m_data = new char[m_length];  // 새로 메모리 할당 
	
			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i]; // for문 돌려서 일일이 복사
		}
		else
			m_data = nullptr;	
	} 
	
	/* 대입 연산자 오버로딩 */
	MyString& operator = (const MyString &source)
	{
		if (this == &source)   // 자기 자신을 대입하는 경우, ex) hello = hello; 
			return *this; // 자기 자신 리턴 
	
		delete[] m_data;   // 자신의 기존 내용물 비워주기 
	
	    /* 아래 과정은 복사생성자 깊은 복사 구현과 같다 */
	
		m_length = source.m_length;
	
		if (source.m_data != nullptr)
		{
			m_data = new char[m_length]; // 새로 메모리 할당 받음 
	
			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
	    else
	        m_data = nullptr;
	} 

	~MyString()  
	{
		delete [] m_data; // 힙 할당 메모리 해제 
	}
};

int main()
{	
	/* 얕은 복사 문제점 */
	MyString hello("Hello");

	cout << (int*)hello.m_data << endl; 
	cout << hello.m_data << endl; // Hello 출력 

	{
		MyString copy = hello; // 디폴트 복사 생성자 호출

		cout << (int*)copy.m_data << endl;
		cout << copy.m_data << endl; // Hello 출력 
		
		// 범위가 끝나면서 copy 객체 소멸
		// 소멸자 호출되면서 주소만 공유했던 "Hello" 메모리도 해제됨 
	}

	cout << hello.m_data << endl; // 이상한 값을 출력함, 해제된 메모리의 쓰레기값 출력 
	
	
	/* 깊은 복사 */
	MyString hello("Hello");

	cout << (int*)hello.m_data << endl; 
	cout << hello.m_data << endl;

	{
		MyString copy = hello;  // 복사 생성자 호출, 깊은 복사 

		cout << (int*)copy.m_data << endl;
		cout << copy.m_data << endl;
	}

	cout << hello.m_data << endl;
	
	/* 대입 연산자 오버로딩*/
	MyString hello("Hello");

	cout << (int*)hello.m_data << endl; 
	cout << hello.m_data << endl;

	{
        Mystring copy;
		copy = hello;  // 오버로딩 한 대입 연산자 호출

		cout << (int*)copy.m_data << endl;
		cout << copy.m_data << endl;
	}

	cout << hello.m_data << endl;

	return 0;


	return 0;
}
