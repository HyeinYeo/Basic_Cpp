#include <iostream>
using namespace std;
/* Derived Class ���� ��� ������ ��� */
/*	
	1. ��� ������ �����ε��� ���� �Լ��θ� ���� ���� 
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
		return base.print(out); // ��� ������ �ȿ����� �Լ� �ϳ��� ȣ��
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
