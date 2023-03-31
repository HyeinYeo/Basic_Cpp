#include <iostream>
using namespace std;
/* �����Լ�: ���� �����Լ�, �߻� Ŭ����, �������̽� */
/*	
	1. ���� ���� �Լ�
		- �Լ��� �ٵ� ���� ���� �Լ�
		- �ڽ� Ŭ�������� �ݵ�� �������̵� �ؾ� �ϴ� �Լ�
		- ����: �ٵ� ���� �Լ��� ������Ÿ�Ը� �ֵ� ���� = 0�� �ٿ��� 
		- "�θ�Ŭ�������� ��� �ؾ� ���� �𸣰����� �ڽ�Ŭ�������� �˾Ƽ� ��üȭ�϶�"
		
	2. �߻� Ŭ����
		- ���� ���� �Լ��� ���� �ϰ� �ִ� Ŭ����
		- �ڽ� Ŭ�������� �̸� �������̵� �� ���� ����
		- �߻� Ŭ������ ��ü�� �� �� ���� 
		- �߻�Ŭ���� ������ ������ ����
		- �߻� Ŭ���� ��� �޴� �ڽ� Ŭ������ �ڵ����� �߻� Ŭ���� ��(���� ���� �Լ� ���� ���� �������� �ҿ���) 
	
	3. �������̽� Ŭ����
		cf. python������ �߻�Ŭ����
		
		- ��� �Լ��� ���� ���� �Լ��� Ŭ����
		- ���θ��� ��� ������ ������ ����
		- �������̽��� ��� �޴� Ŭ�������� �ݵ�� ��� �Լ����� ���� �������̵� �ؾ� ��
		- �������̽��� ��ü ������ �� ���� 
*/

class Animal // �߻� Ŭ���� 
{
protected:
    string m_name;
public:
    Animal(std::string name)
        :m_name(name)
    {}
public:
    string getName() { return m_name; }
    virtual void speak() const = 0;  // ���� ���� �Լ�
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

/* 3. �������̽� Ŭ���� */
class IErrorLog
{
public:
    virtual bool reportError(const char * error) = 0;
    virtual ~IErrorLog() {} // ���� �Ҹ���! 
};


class FileErrorLog : public IErrorLog
{
public:
    bool reportError(const char *errorMessage) override // �� �������̵� 
    {
        cout << "Writing error to a file" << endl;
        return true;
    }
};


class ConsoleErrorLog : public IErrorLog
{
public:
    bool reportError(const char *errorMessage) override // �� �������̵� 
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
    Cow cow("hello");  // �θ��� ���� ���� �Լ��� �������̵� ���� ���� ��� -> ���� �߻�
	cow.speak(); // Moo ��� 
    // Animal ani("Hi");  // ���� �߻�: �߻� Ŭ������ ��ü�� ���� �� ����
    
    
    /* 3. �������̽� Ŭ���� */
    FileErrorLog file_log;
    ConsoleErrorLog console_log;

    doSomething(file_log);   // ������, Writing error to a file ��� 
    doSomething(console_log); // ������, Printing error to a console ��� 
}
