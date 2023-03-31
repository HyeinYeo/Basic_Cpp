#include <iostream>
using namespace std;
/* 예외클래스: 사용자 정의 자료형 */
/*	
	1. 예외 클래스 
		- throw시 예외 클래스를 사용하여 어떤 예외인지 표현
		- 예외 클래스의 '익명 객체'를 생성한 후 throw
	
	2. 예외 클래스 상속
		객체 잘림 현상 발생 시, 
		1) catch 순서 바꾸기
		2) virtual : 부모 예외 클래스에서 가상 함수로 지정
		3) throw;로 던지기 
		
	3. catch문 안에서 re-throw하기
		- 스택 되감기해서 알맞는 catch를 찾는 것! 
		- throw;로 던지면 객체 잘림 안 일어남 
	 

*/
class Exception // 예외 클래스 객체
{
public:
    void report()
    {
        cout << "Exception report" << endl;
    }
};

class MyArray
{
private:
    int m_data[5];
public:
    int & operator [] (const int & index)
    {
        if (index < 0 || index >= 5) throw Exception(); // 예외 클래스 익명 객체 생성 & throw 
        return m_data[index];
    }
};

void doSomething()
{
    MyArray my_array;
    
    try
    {
        my_array[100];
    }
    catch (const int &x)  
    {
        cerr << "Exception " << x << endl;
    }
    catch (Exception &e) // throw Exception(); 받음
    {
        e.report();
    }
}


/* 2. 예외 클래스 상속 */ 
class Exception2
{
public:
    void report()
    {
        cout << "Exception2 report" << endl;
    }
    
    /*
	virtural void report() // virtual 지정 
    {
        cout << "Exception2 report" << endl;
    }
	*/
};

class ArrayException2 : public Exception2
{
public:
    void report()  // 오버라이딩
    {
        cout << "Array Exception2 report" << endl;
    }
};

class MyArray2
{
private:
    int m_data[5];
public:
    int & operator [] (const int & index)
    {
        if (index < 0 || index >= 5) throw ArrayException2();
        return m_data[index];
    }
};

void doSomething2()
{
    MyArray2 my_array;
    
    try
    {
        my_array[100];
    }
    catch (const int &x)
    {
        cerr << "Exception2 " << x << endl;
    }
    catch (ArrayException2 &e)
    {
        e.report();
        throw e;  // re-throw
    }
    
    catch (Exception2 &e)
    {
        e.report();
        throw;
    }
}

int main()
{
	try{
		doSomething();
	
		cout << "main" << endl;
		
		cout << "=========================" << endl;
		doSomething2();
		
		cout << "main2" << endl;
	}
	catch (ArrayException2 &e) // re-throw한 예외 catch함 
    {
       cout << "main()" << endl;
       e.report();
    }
    
    /* 실행 결과
		Exception report
		main
		=========================
		Array Exception2 report
		main()
		Array Exception2 report 
	*/
	return 0;
}
