#include <iostream>
using namespace std;
/* 정적 바인딩 & 동적 바인딩 */
/*	
	1. 정적 바인딩 
		- 실행(런타임) 하지 않는 상태에서도 어떤 함수가 호출될지 명백히 알 수 있는 경우. 
		- 실행전, 빌드 타임에 이미 변수명, 함수 이름들이 다 깔끔하게 정의
		- 실행 중에 직접 함수를 찾아가야 하는 일 없음 
		
		- 장단점
			- 빠름: 실행할 함수가 이미 빌드 때부터 결정
			- 유연성 떨어짐
			 
	2. 동적 바인딩 
		- 어떤 함수가 호출될지는 런타임 중에 결정
		- 런타임 때 직접 함수 포인터를 보고 해당 함수를 찾아가 호출
		- 런타임 때 포인터에 저장된 주소 따라가서 함수 호출 
		
		- 장단점
			- 느림: 런타임 중에 함수의 포인터를 보고 직접 함수를 찾아가 실행
			- 유연, 자유도 높음 
		 
*/

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}


int main()
{
	/* 1. 정적 바인딩 */
    int x1, y1;
    cin >> x1 >> y1;

    int op;

    cout << "0: add, 1: subtract" << endl;
    cin >> op1;

    int result;
    switch(op1)
    {
        case 0 : result = add(x, y); break;
        case 1 : result = subtract(x, y); break;
    }
    
    /* 2. 동적 바인딩 */
    int x2, y2;
    cin >> x2 >> y2;

    int op2;

    cout << "0: add, 1: subtract" << endl;
    cin >> op2;

    int(*func_ptr)(int, int) = nullptr;
    switch(op2)
    {
        case 0 : func_ptr = add; break;
        case 1 : func_ptr = subtract; break;
    }
}
