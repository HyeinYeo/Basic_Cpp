#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
/* std::exception */
#include <exception> // exception 클래스 사용 가능 
/*	
	- throw 없이도 시스템상 내부에서 알아서 예외 종류에 알맞는 std::exception 클래스의 자식 클래스를 throw
	
	1. what()
		- 예외 종류에 맞는 에러 원인 메시지를 리턴하는 기능을 하는 함수
		- 리턴 타입: const char*
		- std::exception 클래스의 모든 자식 클래스는 virtual 가상 함수인 what() 함수 오버라이딩
	
	2. std::exception 상속 받는 사용자 정의 클래스
		- what() 함수 오버라이딩 필수 
		
	
*/

/* 2. std::exception 상속 받는 사용자 정의 클래스 */
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
       s.resize(-1);  // 예외 발생
       throw CustomException(); // catch에서 Custom exception 메시지 출력 
   }
   catch (std::exception &e)
   {
       //std::cout << typeid(e).name() << std::endl;
       std::cerr << e.what() << std::endl; // basic_string::resize 출력
	   									   // => std::length_error 클래스에서는 what() 함수를 "basic_string::resize" 출력 하도록 오버라이딩 
   }
   
   return 0;
}
