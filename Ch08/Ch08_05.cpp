#include <iostream>
#include <string> 
using namespace std;

/* 위임 생성자 */

/*
	생성자가 생성자를 가져다 쓸 수 있게 하는 것 
	같은 클래스 내에서 생성자가 다른 생성자를 호출하는 것
	특정 멤버만 다양한 값으로 초기화 하고 싶을 때 사용 
	
*/
class Student
{
private:
    int m_id;
    string m_name;

public:
    Student(const string &name_in)
        : Student(0, name_in)   // 아래 생성자 호출
        // m_id 멤버는 0으로 초기화 하고 name_in 멤버는 매개변수로 들어온 값으로 초기화
    {}

    Student(const int &id_in, const string &name_in)
        : m_id(id_in), m_name(name_in)
    {}
    
    
    // init 멤버함수로 초기화 하는 법 
    Student(const int &id_in, const string &name_in)
    {
    	init(id_in, name_in); // 만능 초기화 함수 init을 호출해서 초기화 
	}
    
    void init((const int &id_in, const string &name_in))
    {
        m_id = id_in;
        m_name = name_in;
    }
};

int main(){
	Student s("Kim"); // Student(0, "Kim")과 같은 효과 
} 
