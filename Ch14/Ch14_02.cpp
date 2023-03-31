#include <iostream>
using namespace std;
/* 예외처리 & 스택 되감기(stack unwinding) */
/*	
	1. 스택 되감기 => 예외의 전파 
		- throw 던지면, 알맞는 catch를 찾을 때까지(알맞은 예외 처리를 끝낼 때까지) 
		  그 아래 모든 부분들은 스킵한 채로 강제 되감기
		  	-  throw 예외가 일어난 바로 아래 부분에서 찾지 않고, 바로 Skip 후 스택 되감기를 통해 알맞은 catch 탐색 
		- 알맞은 catch를 찾고 나면 찾은 지점 이후부턴 catch 이외의 아래 부분들을 다 정상 실행
		
		**예외의 전파
			- throw한 함수 내에 예외처리 루틴이 없을 경우, 예외처리 루틴 발견할 때까지 caller 함수로 예외 전파 
	
	2. catch(...) 
		- 모든 데이터 타입을 다 받을 수 있는 catch
	
	- 함수() throw()
		void ex1() throw(int)
			- 이 함수는 int 타입의 에러 메세지를 던질 수도 있다는 의미
		
		void ex2() throw(...)
			- 이 함수는 어떤 타입의 에러 메세지든 던질 수도 있다는 의미
			
		void ex3() throw()
			- 이 함수는 예외를 발생시키지 않는다는 의미
			- 함수 내에서 throw 사용 시 에러 발생 

*/
void last()
{
	cout << "Last" << endl;  // 5 
	cout << "Throws exception" << endl;  // 6 

	throw -1;
	cout << "End Last" << endl; // 실행 X 
}

void third()
{
	cout << "Third" << endl; // 4

	last();

	cout << "End third" << endl;  // 실행 X
}

void second()
{
	cout << "Second" << endl; // 3 

	try
	{
		third();
	}
	catch (double)
	{
		std::cerr << "Second caught double exception!" << endl;  // 실행 X
	}
	cout << "End second" << endl;  // 실행 X 
}

void first()
{
	cout << "First" << endl;  // 2

	try
	{
		second();
	}
	catch (int)
	{
		std::cerr << "first caught int exception!" << endl; // 7, throw -1 캐치!
	}
	cout << "End first" << endl; // 8
}

int main()
{
	cout << "Start" << endl;  // 1 

	try
	{
		first(); 
	}
	catch (int)
	{
		std::cerr << "main caught int exception!" << endl;  // 실행 X 
	}
	cout << "End of main" << endl; // 9
}
