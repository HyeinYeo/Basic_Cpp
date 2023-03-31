#include <iostream>
#include <exception>
using namespace std;
/* 예외처리 위험성 & 단점 */ 
/*	
	1. 메모리 누수 발생 가능
	2. 소멸자 안에선 예외를 던지면 안 됨
		- 소멸자는 해당 객체의 메모리를 날려버리는 순간 호출되는 것이기 때문에 
		  정상적으로 예외를 던질 수 있는 상태로 보지 않음
		- 런타임 에러 발생
	
	3. 루프 안에 try-catch 문을 넣는 것은 비추
		- 여러 스택을 왔다 갔다 하기도 하기 때문에 연산이 느림 
	
	4. 모든 오류를 예외처리로 잡으려고 하지 않기
		- 오류 != 예외 
		- 논리적으로 예측이 "어려운" 경우엔 예외처리 
	
*/

int main()
{
	try
	{
		int * i = new int[1000000];  // 꽤 큰 메모리 할당

		throw "error";  

		delete[] i; // 에러 발생 시 throw되어 이 메모리 해제가 실행되지 못함 
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}
	return 0;
}
