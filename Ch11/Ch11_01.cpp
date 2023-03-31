#include <iostream>
#include <string>
using namespace std;
/* 상속 */
/*	0. 상속 기본 개념
		- 소프트웨어 재사용
		- 동적 바인딩
		- 다중상속 허용
		 
	1. 상속 방법 
		class Son : public Mother
		
	2. 특징
		- 부모 클래스의 멤버들(변수, 함수)을 모두 물려받음
		- private한 멤버 변수도 다 상속됨, but 자식클래스에서 접근 불가
			- protected
				private 상태 유지하면서 자식 클래스는 사용 가능하게 함! 
			- 부모클래스의 멤버함수 통해서 private 변수 간접접근 & 변경 가능
				부모클래스::멤버함수( )
		- 상속 받으면 빈 클래스임에도 불구하고 사이즈 출력됨 
		
	3. 오버라이딩
		- 오버라이딩한 함수가 호출됨
		
	4. 생성자
		- 부모클래스로부터 받은 변수, 자식클래스의 변수를 초기화하기 위함 
		
		- 생성자 호출 / 처리 순서
			1) 생성자의 인수를 받는 부분
			2) 생성자 초기화 리스트 부분
				- 자식클래스 메모리 할당 
					생성자 초기화 리스트에 있는 자기 자신의 멤버들은 쓰레기값만 들어있는 상태
				- 부모 생성자 호출 -> 부모로부터 상속받은 멤버들 초기화
					물려 받은 멤버는 할당 + 초기화까지 완료
			3) 생성자 초기화 리스트에 있는 자기 자신의 멤버들 초기화 
			4) 자신의 생성자 내부 {} 중괄호 부분 처리
				자신만의 멤버들을 초기화 
		
		- 생성자 초기화 리스트에서 부모 멤버를 초기화 시킬 순 없다(아직 부모 생성자 호출 전이기 때문)-> 해결법은? 
			- 부모의 접근 함수 호출
			- 초기화 리스트에서 부모 생성자 직접 호출
				- 생성자 초기화 리스트 안에서 직접 부모 생성자를 호출
				- 위임 생성자 사용
		
		- ** 주의사항 : 부모의 디폴트 생성자가 없을 경우
	 
*/

class Person{
private:
	std::string m_name;
	
protected: // private 상태 유지하면서 자식 클래스는 사용 가능
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
	// 생성자 
	Student(const string &name = "None", const char &gender = 'N', const int &num = 0){
		Person::setName(name);
		Person::setGender(gender);
		m_num = num; 
	}
	
	void doSth()  // 오버라이딩
	{
	  cout << "Student class" << endl;  // 내용을 바꿈 
	}
	
	/*void get() const{
		cout << m_name << endl;
	}*/ // => 부모 클래스의 private 멤버변수 사용 불가
	
	// 오버라이딩 & 부모 private 변수 변경 
	void setName(const string &name){
		Person::setName(name);
	}
	void transgender(const char &new_gender){ // protected 변수는 사용 가능 
		m_gender = new_gender; 
	}
};

int main(){
	Person p;
	p.setName("사람");
	cout << p.getName() << endl;
	
	Student s;
	s.setName("Sam"); // 오버라이딩 된 setName() 호출 -> 부모의 setName() 호출 
	cout << "개명 전: " << s.getName() << endl;
	s.setName("Tom"); // 오버라이딩 된 setName() 호출 -> 부모의 setName() 호출 
	cout << "개명 후: " << s.getName() << endl;
	
	cout << sizeof(s) << endl;
	
	cout << "--------------------------" << endl;
	
	// 오버라이딩 
	p.doSth(); // Person class 출력 
	s.doSth(); // Student class 출력 
	
	cout << "--------------------------" << endl;
	// protected 변수
	p.setGender('M');
	cout << "person의 젠더: " << p.getGender() << endl;
	
	s.setGender('F');
	cout << "student 전환 전: "<< s.getGender() << endl;
	s.transgender('M');
	cout << "student 전환 후: " << s.getGender() << endl; 
	
} 
