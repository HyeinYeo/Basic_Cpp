#include <iostream>
#include <exception>
using namespace std;
/* function try */ 
/*	
	A 생성자에서 발생한 예외를 
	(A 생성자를 호출한 B 생성자를 호출한) main이 아닌
	바로 B 생성자 아래에서 예외를 catch 하고 싶다면?
	
	==> B 생성자 함수 끝에 try 붙이기
		B(int x) try {}
		
	- 함수 하나 전체를 try로 묶음
	- 함수 try의 예외를 받은 catch에선 명시되어있지 않아도 한번 더 예외를 throw
	  (re-throw가 작동하는 것처럼 catch 또 일어날 수 있음)
		
	
*/

class A
{
private:
    int m_x;
public:
    A(int x) : m_x(x)
    {
        if (x == 0)
            throw 1;
    }
};

class B : public A
{
public:
    B(int x) try // 생성자 function try
        : A(x)
    {}

    catch(...)
    {
        std::cout << "Catch in B constructor" << std::endl;
        // throw;가 있는 것처럼 작동하여 main에서도 또 캐치함 (re-throw한 것처럼)
    }
};

int main()
{
   try
   {
       B b(0);
   }
   catch (...)
   {
       std::cout << "Catch in main()" << std::endl;
   }
   
   /* 결과 
   	  Catch in B constructor
      Catch in main() 
   */
   return 0;
}
