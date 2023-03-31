#include <iostream>
#include <string>
using namespace std;
/* ��� */
/*	0. ��� �⺻ ����
		- ����Ʈ���� ����
		- ���� ���ε�
		- ���߻�� ���
		 
	1. ��� ��� 
		class Son : public Mother
		
	2. Ư¡
		- �θ� Ŭ������ �����(����, �Լ�)�� ��� ��������
		- private�� ��� ������ �� ��ӵ�, but �ڽ�Ŭ�������� ���� �Ұ�
			- protected
				private ���� �����ϸ鼭 �ڽ� Ŭ������ ��� �����ϰ� ��! 
			- �θ�Ŭ������ ����Լ� ���ؼ� private ���� �������� & ���� ����
				�θ�Ŭ����::����Լ�( )
		- ��� ������ �� Ŭ�����ӿ��� �ұ��ϰ� ������ ��µ� 
		
	3. �������̵�
		- �������̵��� �Լ��� ȣ���
		
	4. ������
		- �θ�Ŭ�����κ��� ���� ����, �ڽ�Ŭ������ ������ �ʱ�ȭ�ϱ� ���� 
		
		- ������ ȣ�� / ó�� ����
			1) �������� �μ��� �޴� �κ�
			2) ������ �ʱ�ȭ ����Ʈ �κ�
				- �ڽ�Ŭ���� �޸� �Ҵ� 
					������ �ʱ�ȭ ����Ʈ�� �ִ� �ڱ� �ڽ��� ������� �����Ⱚ�� ����ִ� ����
				- �θ� ������ ȣ�� -> �θ�κ��� ��ӹ��� ����� �ʱ�ȭ
					���� ���� ����� �Ҵ� + �ʱ�ȭ���� �Ϸ�
			3) ������ �ʱ�ȭ ����Ʈ�� �ִ� �ڱ� �ڽ��� ����� �ʱ�ȭ 
			4) �ڽ��� ������ ���� {} �߰�ȣ �κ� ó��
				�ڽŸ��� ������� �ʱ�ȭ 
		
		- ������ �ʱ�ȭ ����Ʈ���� �θ� ����� �ʱ�ȭ ��ų �� ����(���� �θ� ������ ȣ�� ���̱� ����)-> �ذ����? 
			- �θ��� ���� �Լ� ȣ��
			- �ʱ�ȭ ����Ʈ���� �θ� ������ ���� ȣ��
				- ������ �ʱ�ȭ ����Ʈ �ȿ��� ���� �θ� �����ڸ� ȣ��
				- ���� ������ ���
		
		- ** ���ǻ��� : �θ��� ����Ʈ �����ڰ� ���� ���
	 
*/

class Person{
private:
	std::string m_name;
	
protected: // private ���� �����ϸ鼭 �ڽ� Ŭ������ ��� ����
	char m_gender;
	
public:
	Person(const string &name = "No Name"){
		m_name = name;
	}
	void setName(const string &name){
		m_name = name;
	}
	string getName() const{
		return m_name;
	}
	
	void doSth(){
		cout << "Person class" << endl;
	}
	
	void setGender(const char &gender = 'N'){
		m_gender = gender;
	}
	
	char getGender() const{
		return m_gender;
	}
}; 

class Student : public Person{
private:
	int m_num;	

public:
	// ������ 
	Student(const string &name = "None", const char &gender = 'N', const int &num = 0){
		Person::setName(name);
		Person::setGender(gender);
		m_num = num; 
	}
	
	void doSth()  // �������̵�
	{
	  cout << "Student class" << endl;  // ������ �ٲ� 
	}
	
	/*void get() const{
		cout << m_name << endl;
	}*/ // => �θ� Ŭ������ private ������� ��� �Ұ�
	
	// �������̵� & �θ� private ���� ���� 
	void setName(const string &name){
		Person::setName(name);
	}
	void transgender(const char &new_gender){ // protected ������ ��� ���� 
		m_gender = new_gender; 
	}
};

int main(){
	Person p;
	p.setName("���");
	cout << p.getName() << endl;
	
	Student s;
	s.setName("Sam"); // �������̵� �� setName() ȣ�� -> �θ��� setName() ȣ�� 
	cout << "���� ��: " << s.getName() << endl;
	s.setName("Tom"); // �������̵� �� setName() ȣ�� -> �θ��� setName() ȣ�� 
	cout << "���� ��: " << s.getName() << endl;
	
	cout << sizeof(s) << endl;
	
	cout << "--------------------------" << endl;
	
	// �������̵� 
	p.doSth(); // Person class ��� 
	s.doSth(); // Student class ��� 
	
	cout << "--------------------------" << endl;
	// protected ����
	p.setGender('M');
	cout << "person�� ����: " << p.getGender() << endl;
	
	s.setGender('F');
	cout << "student ��ȯ ��: "<< s.getGender() << endl;
	s.transgender('M');
	cout << "student ��ȯ ��: " << s.getGender() << endl; 
	
} 
