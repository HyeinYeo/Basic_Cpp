#include <iostream>
using namespace std;

/* const 함수 오버로딩 */
/* 
	- const 의 유무도 오버로딩의 고려 대상이 됨 
		- const로 선언한 객체는 const 함수만 호출 가능
		- const 없이 선언한 갹체는 const 없는 함수 호출 
	
	- const가 앞에 붙은 함수
		- 단순히 리턴을 변경할 수 없는 상수로 하겠다는 의미
	- const가 뒤에 붙은 함수
		- const 객체만 사용할 수 있는 함수로서
		  멤버 값을 변경하지 않겠다는 의미
 */
 
#include <iostream>
#include <string>

class Something
{
public:
    string m_value = "default";

    const string& getValue() const
    {
        cout << "const version" << endl;
        return m_value;
    }

    string& getValue()
    {
        cout << "non-const version" << endl;
        return m_value;
    }
}

int main()
{
    Something s1;
    s1.getValue();   // string& getValue() 호출
    s1.getValue() = 10; // 가능 

    const Something s2;
    s2.getValue();  // const string& getValue() const 호출
}
