#include <iostream>
using namespace std;
/* Derived Class 에서 출력 연산자 사용 */
/*	
	1. 출력 연산자 오버로딩은 전역 함수로만 구현 가능 
*/
class Base
{
private:
	int m_base;
public:
	Base(const int& input = 0)
		:m_base(input) {}
	friend ostream& operator << (ostream& out, const Base& base)
	{
		return base.print(out); // 출력 연산자 안에서는 함수 하나만 호출
	}
	virtual ostream& print(ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	virtual ostream& print(ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};
int main()
{
    Base b;
    std::cout << b << '\n';

    Derived d;
    std::cout << d << '\n';

    Base & bref = d;
    std::cout << bref << '\n';
}
