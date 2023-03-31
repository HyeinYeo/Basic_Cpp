#include <iostream>
using namespace std;
/* 예외처리의 기본 */
/*
	assert: 컴파일 타임에 검사 
	
	1. try
		- 예외가 발생하지 않으면 try부분만 실행
		
		** 중첩 try 가능
		- 안쪽 try블록에서 throw한 예외를 처리할 catch루틴 없으면,
		  바깥 try블록으로 예외 전파 -> 바깥 try블록의 catch루틴에서 찾음 
	
	2. throw
		- catch에게 에러 메세지 던짐
		- try 블록 안에서 실행되어야 함
			- 밖에 선언되어도 컴파일 오류는 발생하지 않지만, abort()로 프로그램 중단됨 
		 
	3. catch
		- throw가 던진 에러 메세지를 받아서 예외 발생에 대한 대응을 처리(예외처리 부분)
	   	- 예외 매개변수는 한 개만 선언 가능 
	   	- 예외처리할 catch 블록 없으면 abort()로 프로그램 중단됨
		- catch 블록 안에서도 try~catch 블록 선언 가능 
	
	- 예외 처리는 자동 형변환 X
		- throw가 catch에게 에러 메세지를 전달할 때 주의
	- throw가 던진 것에 대해 타입이 알맞는 catch 실행
		- 딱 맞는 타입 없으면 런타임 에러 발생시킴(자동 형변환 X) 
		
	
*/

int main()
{
    double x;
    cin >> x;  // 음수 입력시 예외 발생하도록
    
    try
    {
        if (x < 0.0) throw string("Negative input"); // string 타입 
        // if (x < 0.0) throw "Negative input"; // const char * 타입
        
        cout << x + 1 << endl;
    }
    catch (string error_message)
    {
        cout << error_message << endl;
    }
    
    // 타입이 알맞는 catch 실행 - 1 
    try
    {
        throw -1; // catch (int x) 실행 
    }
    catch (int x)
    {
        cout << "Catch Integer " << x << endl;
    }
    catch (string error_message)
    {
        cout << error_message << endl;
    }
    
    // 타입 알맞는 catch 실행 - 2
	try
    {
        throw "My error message"; // catch (const char *error_message) 실행 
    }
    catch (double x)
    {
        cout << "Catch double" << endl;
    }
    catch (const char *error_message)
    {
        cout <<  "const char * " << error_message << endl;
    } 

    return 0;
}
