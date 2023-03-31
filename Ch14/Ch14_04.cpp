#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
/* std::exception */
#include <exception> // exception Ŭ���� ��� ���� 
/*	
	- throw ���̵� �ý��ۻ� ���ο��� �˾Ƽ� ���� ������ �˸´� std::exception Ŭ������ �ڽ� Ŭ������ throw
	
	1. what()
		- ���� ������ �´� ���� ���� �޽����� �����ϴ� ����� �ϴ� �Լ�
		- ���� Ÿ��: const char*
		- std::exception Ŭ������ ��� �ڽ� Ŭ������ virtual ���� �Լ��� what() �Լ� �������̵�
	
	2. std::exception ��� �޴� ����� ���� Ŭ����
		- what() �Լ� �������̵� �ʼ� 
		
	
*/

/* 2. std::exception ��� �޴� ����� ���� Ŭ���� */
class CustomException : public std::exception 
{
public:
    const char* what() const throw() override
    {
        return "Custom exception";
    }
};


int main()
{
   try
   {
       std::string s;
       s.resize(-1);  // ���� �߻�
       throw CustomException(); // catch���� Custom exception �޽��� ��� 
   }
   catch (std::exception &e)
   {
       //std::cout << typeid(e).name() << std::endl;
       std::cerr << e.what() << std::endl; // basic_string::resize ���
	   									   // => std::length_error Ŭ���������� what() �Լ��� "basic_string::resize" ��� �ϵ��� �������̵� 
   }
   
   return 0;
}
