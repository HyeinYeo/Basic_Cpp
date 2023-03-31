#include <iostream>
using namespace std;
/* 가상함수: 순수 가상함수, 추상 클래스, 인터페이스 */
/*	
	1. 순수 가상 함수
		- 함수의 바디가 없는 가상 함수
		- 자식 클래스에서 반드시 오버라이딩 해야 하는 함수
		- 선언: 바디 없이 함수의 프로토타입만 있되 끝에 = 0을 붙여줌 
		- "부모클래스에선 어떻게 해야 할지 모르겠으니 자식클래스에서 알아서 구체화하라"
		
	2. 추상 클래스
		- 순수 가상 함수를 포함 하고 있는 클래스
		- 자식 클래스들이 이를 오버라이딩 할 것을 강제
		- 추상 클래스는 객체로 찍어낼 수 없음 
		- 추상클래스 포인터 선언은 가능
		- 추상 클래스 상속 받는 자식 클래스는 자동으로 추상 클래스 됨(순수 가상 함수 전부 구현 전까지는 불완전) 
	
	3. 인터페이스 클래스
		cf. python에서의 추상클래스
		
		- 모든 함수가 순수 가상 함수인 클래스
		- 본인만의 멤버 변수는 가지지 않음
		- 인터페이스를 상속 받는 클래스들은 반드시 모든 함수들을 전부 오버라이딩 해야 함
		- 인터페이스로 객체 생성할 수 없음 
*/

class Animal // 추상 클래스 
{
protected:
    string m_name;
public:
    Animal(std::string name)
        :m_name(name)
    {}
public:
    string getName() { return m_name; }
    virtual void speak() const = 0;  // 순수 가상 함수
};


class Cow : public Animal
{
protected:
    string m_name;
public:
    Cow(std::string name)
        :Animal(name)
    {}
    
    virtual void speak() const{
		cout << "Moo" << endl;
	}
};


void Animal::speak() const
{
    cout << m_name << endl;
}

/* 3. 인터페이스 클래스 */
class IErrorLog
{
public:
    virtual bool reportError(const char * error) = 0;
    virtual ~IErrorLog() {} // 가상 소멸자! 
};


class FileErrorLog : public IErrorLog
{
public:
    bool reportError(const char *errorMessage) override // 꼭 오버라이딩 
    {
        cout << "Writing error to a file" << endl;
        return true;
    }
};


class ConsoleErrorLog : public IErrorLog
{
public:
    bool reportError(const char *errorMessage) override // 꼭 오버라이딩 
    {
        cout << "Printing error to a console" << endl;
        return true;
    }
};


void doSomething(IErrorLog &log)
{
    log.reportError("Runtime error!!");
}


int main()
{
    Cow cow("hello");  // 부모의 순수 가상 함수를 오버라이딩 하지 않을 경우 -> 에러 발생
	cow.speak(); // Moo 출력 
    // Animal ani("Hi");  // 에러 발생: 추상 클래스로 객체를 만들어낼 수 없음
    
    
    /* 3. 인터페이스 클래스 */
    FileErrorLog file_log;
    ConsoleErrorLog console_log;

    doSomething(file_log);   // 다형성, Writing error to a file 출력 
    doSomething(console_log); // 다형성, Printing error to a console 출력 
}
