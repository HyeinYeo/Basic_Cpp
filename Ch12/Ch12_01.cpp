#include <iostream>
using namespace std;
/* ������ */
/*	
	1. ������ 
		- �θ� Ÿ���� ������ �� �ϳ��� ���� �ڽĵ��� ����� ȣ��
		
		- �����ϴ� ����� Ÿ���� �ƴ�,
		  ����� ȣ���ϴ� ����(������ Ȥ�� ��ü����)�� Ÿ�Կ� ���� �� Ÿ�Կ� �´� ����� ȣ��
		  => Animal *ptr_animal1 = &cat;
		  => ptr_animal1�� CatŸ�� ��ü�� �ּҸ� ��� ������ ptr_animal1 ��ü�� Animal Ÿ��
		  => Animal�� speak() ��� �Լ� ȣ��(����Ʈ ����, ȣ�� ������ Ÿ�� �߽��ϹǷ�)
	
	2. ��� ����
		- �ڽ� Ŭ���� ������ �����������, �ڽĸ��� ������ �ڽ�Ÿ�� ������ ����Լ� ȣ���ؾ� ��
		- �θ� Ŭ������ �� ���� �������
		
		==> �ڽ�Ŭ�������� �������̵� �� speak()�� ȣ���ϴ� ���? -> �����Լ� ����
	
	3. virtual �����Լ� 
		- �θ� Ÿ�� �����ͷ� �ڽ� ��ü�� ����ų ��, 
		  �ڽ��� �������̵� �� ���� ȣ���ϰ� �ϰ� ���� ��� �Լ��� 
		  virtual ���� �Լ��� ����(�θ� Ŭ��������)
		- �ڽ� Ŭ�������� �������̵� �Ǿ� ���� ������ �θ� �����س��� �θ�Ÿ���� ���� �Լ� ȣ��
*/

class Animal
{
protected:
	string m_name;

public:
	Animal(std::string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }
	
	/*
	void speak() const
	{
		cout << m_name << " ??? " << endl;
	}
	*/
	
	/* 3. �����Լ� */
	virtual void speak() const
	{
		cout << m_name << " ??? " << endl;
	}
	
};

class Cat : public Animal
{
public:
	Cat(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Meow " << endl;
	}

};

class Dog : public Animal
{
public:
	Dog(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Woof " << endl;
	}
};

int main()
{
	Animal animal("my animal");
	Cat cat("my cat");
	Dog dog("my dog");

	animal.speak();  // "my animal ???" ���
	cat.speak();     // "my cat Meow" ���
	dog.speak();     // "my dog Woof" ���
	
	Animal *ptr_animal1 = &cat;
	Animal *ptr_animal2 = &dog;

	ptr_animal1->speak();  // "my cat ???" ���
	ptr_animal2->speak();  // "my dog ???" ���
	
	// --------------------------------------------
	cout << "--------------------" << endl;
	Cat cats[] = {Cat("cat1"), Cat("cat2"), Cat("cat3")};
	Dog dogs[] = {Dog("dog1"), Dog("dog2")};
	
	Animal *animals[] = {&cats[0], &cats[1], &cats[2], &dogs[0], &dogs[1]};
	for (int i = 0; i < 5; i++)
		animals[i] -> speak();
	/*
	<virtual ���� ��, ��� ���>
	cat1 ???
	cat2 ???
	cat3 ???
	dog1 ???
	dog2 ???
	*/
	
	/*
	<virtual ���� ��, ��� ���>
	cat1 Meow
	cat2 Meow
	cat3 Meow
	dog1 Woof
	dog2 Woof
	
	-> �������̵� �� speak() ȣ��� 
	*/	
	
		
	return 0;
}
