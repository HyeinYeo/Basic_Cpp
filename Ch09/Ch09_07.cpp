#include <iostream>
using namespace std;
/* 괄호 연산자 오버로딩 */
/*	
	<괄호 연산자>
		()
	
	<괄호 연산자 오버로딩>
		- () => 주로 함수 호출할 때 사용
		- 객체(인수)로 함수처럼 동작하고 싶을 때 사용하는 연산자 오버로딩
		- **멤버 함수로만 구현이 가능!!!	
*/

class Accumulator
{
private:
	int m_counter = 0;

public:
	int operator () (int i) 
    { 
        return (m_counter += i); 
        // 현재 값에 들어온 값 누적하여 리턴 
    } 
};

int main()
{
	Accumulator acc;

	cout << acc(10) << endl; // 10 출력
	cout << acc(20) << endl; // 30 출력

	return 0;
}
