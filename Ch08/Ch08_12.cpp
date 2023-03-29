#include <iostream>
using namespace std;

/* 친구함수와 클래스 */
/* 
	- 클래스에서 어떤 함수나 다른 클래스를 friend로 지정
	  => 자신의 private 멤버들에도 자유롭게 접근할 수 있게 허락
	  
	- 함수를 친구로 지정
		friend + 함수의 선언  
	
	- 클래스를 친구로 지정 
		friend class 클래스명 
		- 친구 클래스가 원클래스의 모든 private 멤버들에 접근 가능 
		
		- 친구 멤버함수
			friend <반환자료형> 클래스명::함수명(); 
			- 다른 클래스의 일부 멤버함수에만 private 멤버 접근을 허용하고 싶을 때
		
	* 전방선언 
		- 컴파일러에게 Y 클래스라는 것이 있다는 것을 X 클래스 선언 전에 미리 알려주는 것

 */

/* 함수를 친구로 지정 */
class A
{
private:
    int m_value = 1;
    friend void doSomething(A& a);  // 친구로 지정
};

void doSomething(A& a)
{
    cout << a.m_value << endl; // friend 없으면, 에러 발생 
}

/* 전방 선언 */
class Y; // 미리 프로토타입만 전방 선언

class X
{
private:
    int m_value = 1;
    friend void doSomething2(X& x, Y& y);  // 에러 발생 
    // 아직 B 클래스가 선언되기 전이기 때문에 doSomething2의 매개변수인 Y& y 를 보고 Y가 누군지 모름 
};

class Y
{
private:
    int m_value = 1;
    friend void doSomething2(X& x, Y& y);  // 친구로 지정
};


void doSomething2(X& x, Y& y)
{
    cout << x.m_value << endl; // friend 없으면, 에러 발생 
    cout << y.m_value << endl;
}

/* 클래스를 친구로 지정 */
class Q; // 전방선언
 

class P
{
private:
    int m_value = 1;
	
	// Q 클래스를 친구로 삼음 : P 클래스의 모든 private 멤버들에 접근 가능
    friend class Q;   
    
    // 친구 멤버함수 : 일부 멤버함수에만 private 멤버 접근을 허용
	friend void Q::func_2(P& p);  // Q의 특정 멤버 함수를 친구로 선언
    
    
};


class Q   // P 클래스의 모든 private 멤버들에 접근 가능 
{
private:
    int m_value = 1;

    void func_1(P& p)   
    {
        cout << p.m_value << endl; // Q
    }

    void func_2(P& p)   
    {
        p.m_value++;
    }
};


/* 친구 멤버함수 : 일부 멤버함수에만 private 멤버 접근을 허용 */
class F; // G 클래스의 멤버변수의 매개변수 F& f에서 F를 모르기 때문에 전방선언  

class G   
{
private:
    int m_value = 1;

    void func_1(F& f)   
    {
        cout << f.m_value << endl; // 오류 발생 
    }

    void func_2(F& f);   // 이 함수만 F 클래스의 private 멤버에 접근 가능 
    // F가 G 뒤에 있으면 F가 선언 전이라 F의 m_value를 알 수 없으므로,
    // 여기서 함수는 선언만 하고 정의는 F 클래스 후에 한다. 

};

class F
{
private:
    int m_value = 1; 
    
    // 친구 멤버함수
	friend void G::func_2(F& f);  // G의 특정 멤버 함수를 친구로 선언
};

void G::func_2(F& f){ // G 클래스의 친구 멤버함수 정의는 여기서!!!! 
    f.m_value++;
} 



