#include <iostream>
#include <cassert>
using namespace std;
/* ÷�� ������ �����ε� */
/*	
	<÷�� ������>
		[]
	
	<÷�� ������ �����ε�>
		- ��ü�� �迭�̳� ������ ����� ��ü[index]�� "�ٷ� �����ϰ� ���� ��" ����ϴ� ������ �����ε�
		- �Լ��� ��ġ�� �ʰ� ��ü[index] �����ε� �ٷ� �ش� ��ü�� �迭 ����� ������ �� �ֵ���
		- **��� �Լ��θ� ������ ����!!!	
*/
class IntList
{
private:
	int m_list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

public:
	int& operator [] (const int index) // ��ü�� ��� m_list[3] ���� ������ ���� => L-valueó�� ��� ���� 
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}
	
	// �迭 ��� �б⸸ �����ϰ� ����� => const
	const int& operator [](const int index) const //�Լ� �ȿ��� ����� ���� �ٲ��� �ʰڴٴ� ��!
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}
};

int main()
{
	IntList my_list1;
	my_list1[3] = 10; // L-valueó�� ��� ����
	
	
	const IntList my_list2; // const ���� ��� �Լ��� ��� ���� 
	my_list2[3] = 10;// ���� �߻�(���� �Ұ���) 
	cout << my_list2[3] << endl; // �б⸸ ����
	
	// ������ ��ü ��� �� ���ǻ���
	InList *list = new InList; // ��ü�� �������� �Ҵ� �޾� �����ͷ� ����
	(*list)[3] = 10; //list[3]�� �ƴ϶� (*list)[3]���� ��� ��! ��ü[]�� ȣ���ؾ� �ϴϱ� ������
	

	return 0;
}
