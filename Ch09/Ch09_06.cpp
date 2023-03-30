#include <iostream>
#include <cassert>
using namespace std;
/* 첨자 연산자 오버로딩 */
/*	
	<첨자 연산자>
		[]
	
	<첨자 연산자 오버로딩>
		- 객체의 배열이나 벡터인 멤버를 객체[index]로 "바로 접근하고 싶을 때" 사용하는 연산자 오버로딩
		- 함수를 거치지 않고 객체[index] 만으로도 바로 해당 객체의 배열 멤버에 접근할 수 있도록
		- **멤버 함수로만 구현이 가능!!!	
*/
class IntList
{
private:
	int m_list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

public:
	int& operator [] (const int index) // 객체의 멤버 m_list[3] 값을 참조로 리턴 => L-value처럼 사용 가능 
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}
	
	// 배열 멤버 읽기만 가능하게 만들기 => const
	const int& operator [](const int index) const //함수 안에서 멤버의 값을 바꾸지 않겠다는 것!
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}
};

int main()
{
	IntList my_list1;
	my_list1[3] = 10; // L-value처럼 사용 가능
	
	
	const IntList my_list2; // const 붙은 멤버 함수만 사용 가능 
	my_list2[3] = 10;// 오류 발생(수정 불가능) 
	cout << my_list2[3] << endl; // 읽기만 가능
	
	// 포인터 객체 사용 시 주의사항
	InList *list = new InList; // 객체를 동적으로 할당 받아 포인터로 참조
	(*list)[3] = 10; //list[3]이 아니라 (*list)[3]으로 써야 함! 객체[]로 호출해야 하니까 역참조
	

	return 0;
}
