#include <iostream>
#include <string> 
using namespace std;

/* ���� ������ */

/*
	�����ڰ� �����ڸ� ������ �� �� �ְ� �ϴ� �� 
	���� Ŭ���� ������ �����ڰ� �ٸ� �����ڸ� ȣ���ϴ� ��
	Ư�� ����� �پ��� ������ �ʱ�ȭ �ϰ� ���� �� ��� 
	
*/
class Student
{
private:
    int m_id;
    string m_name;

public:
    Student(const string &name_in)
        : Student(0, name_in)   // �Ʒ� ������ ȣ��
        // m_id ����� 0���� �ʱ�ȭ �ϰ� name_in ����� �Ű������� ���� ������ �ʱ�ȭ
    {}

    Student(const int &id_in, const string &name_in)
        : m_id(id_in), m_name(name_in)
    {}
    
    
    // init ����Լ��� �ʱ�ȭ �ϴ� �� 
    Student(const int &id_in, const string &name_in)
    {
    	init(id_in, name_in); // ���� �ʱ�ȭ �Լ� init�� ȣ���ؼ� �ʱ�ȭ 
	}
    
    void init((const int &id_in, const string &name_in))
    {
        m_id = id_in;
        m_name = name_in;
    }
};

int main(){
	Student s("Kim"); // Student(0, "Kim")�� ���� ȿ�� 
} 
