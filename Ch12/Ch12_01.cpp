#include <iostream>
using namespace std;
/* 다형성 */
/*	
	1. 다형성 
		- 부모 타입의 포인터 딱 하나로 여러 자식들의 멤버를 호출
		
		- 참조하는 대상의 타입이 아닌,
		  멤버를 호출하는 변수(포인터 혹은 객체변수)의 타입에 따라 그 타입에 맞는 멤버를 호출
		  => Animal *ptr_animal1 = &cat;
		  => ptr_animal1은 Cat타입 객체의 주소를 담고 있지만 ptr_animal1 자체는 Animal 타입
		  => Animal의 speak() 멤버 함수 호출(포인트 변수, 호출 변수의 타입 중시하므로)
	
	2. 사용 이유
		- 자식 클래스 종류가 여러가지라면, 자식마다 일일이 자식타입 변수로 멤버함수 호출해야 함
		- 부모 클래스로 한 번에 묶어버림
		
		==> 자식클래스마다 오버라이딩 한 speak()를 호출하는 방법? -> 가상함수 지정
	
	3. virtual 가상함수 
		- 부모 타입 포인터로 자식 객체를 가리킬 시, 
		  자식이 오버라이딩 한 것을 호출하게 하고 싶은 멤버 함수를 
		  virtual 가상 함수로 지정(부모 클래스에서)
		- 자식 클래스에서 오버라이딩 되어 있지 않으면 부모가 정의해놓은 부모타입의 가상 함수 호출
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
	
	/* 3. 가상함수 */
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

	animal.speak();  // "my animal ???" 출력
	cat.speak();     // "my cat Meow" 출력
	dog.speak();     // "my dog Woof" 출력
	
	Animal *ptr_animal1 = &cat;
	Animal *ptr_animal2 = &dog;

	ptr_animal1->speak();  // "my cat ???" 출력
	ptr_animal2->speak();  // "my dog ???" 출력
	
	// --------------------------------------------
	cout << "--------------------" << endl;
	Cat cats[] = {Cat("cat1"), Cat("cat2"), Cat("cat3")};
	Dog dogs[] = {Dog("dog1"), Dog("dog2")};
	
	Animal *animals[] = {&cats[0], &cats[1], &cats[2], &dogs[0], &dogs[1]};
	for (int i = 0; i < 5; i++)
		animals[i] -> speak();
	/*
	<virtual 적용 전, 출력 결과>
	cat1 ???
	cat2 ???
	cat3 ???
	dog1 ???
	dog2 ???
	*/
	
	/*
	<virtual 적용 후, 출력 결과>
	cat1 Meow
	cat2 Meow
	cat3 Meow
	dog1 Woof
	dog2 Woof
	
	-> 오버라이딩 된 speak() 호출됨 
	*/	
	
		
	return 0;
}
