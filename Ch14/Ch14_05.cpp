#include <iostream>
#include <exception>
using namespace std;
/* function try */ 
/*	
	A �����ڿ��� �߻��� ���ܸ� 
	(A �����ڸ� ȣ���� B �����ڸ� ȣ����) main�� �ƴ�
	�ٷ� B ������ �Ʒ����� ���ܸ� catch �ϰ� �ʹٸ�?
	
	==> B ������ �Լ� ���� try ���̱�
		B(int x) try {}
		
	- �Լ� �ϳ� ��ü�� try�� ����
	- �Լ� try�� ���ܸ� ���� catch���� ��õǾ����� �ʾƵ� �ѹ� �� ���ܸ� throw
	  (re-throw�� �۵��ϴ� ��ó�� catch �� �Ͼ �� ����)
		
	
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
    B(int x) try // ������ function try
        : A(x)
    {}

    catch(...)
    {
        std::cout << "Catch in B constructor" << std::endl;
        // throw;�� �ִ� ��ó�� �۵��Ͽ� main������ �� ĳġ�� (re-throw�� ��ó��)
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
   
   /* ��� 
   	  Catch in B constructor
      Catch in main() 
   */
   return 0;
}
