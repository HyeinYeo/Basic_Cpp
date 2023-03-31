#include <iostream>
using namespace std;
/* ����ó���� �⺻ */
/*
	assert: ������ Ÿ�ӿ� �˻� 
	
	1. try
		- ���ܰ� �߻����� ������ try�κи� ����
		
		** ��ø try ����
		- ���� try��Ͽ��� throw�� ���ܸ� ó���� catch��ƾ ������,
		  �ٱ� try������� ���� ���� -> �ٱ� try����� catch��ƾ���� ã�� 
	
	2. throw
		- catch���� ���� �޼��� ����
		- try ��� �ȿ��� ����Ǿ�� ��
			- �ۿ� ����Ǿ ������ ������ �߻����� ������, abort()�� ���α׷� �ߴܵ� 
		 
	3. catch
		- throw�� ���� ���� �޼����� �޾Ƽ� ���� �߻��� ���� ������ ó��(����ó�� �κ�)
	   	- ���� �Ű������� �� ���� ���� ���� 
	   	- ����ó���� catch ��� ������ abort()�� ���α׷� �ߴܵ�
		- catch ��� �ȿ����� try~catch ��� ���� ���� 
	
	- ���� ó���� �ڵ� ����ȯ X
		- throw�� catch���� ���� �޼����� ������ �� ����
	- throw�� ���� �Ϳ� ���� Ÿ���� �˸´� catch ����
		- �� �´� Ÿ�� ������ ��Ÿ�� ���� �߻���Ŵ(�ڵ� ����ȯ X) 
		
	
*/

int main()
{
    double x;
    cin >> x;  // ���� �Է½� ���� �߻��ϵ���
    
    try
    {
        if (x < 0.0) throw string("Negative input"); // string Ÿ�� 
        // if (x < 0.0) throw "Negative input"; // const char * Ÿ��
        
        cout << x + 1 << endl;
    }
    catch (string error_message)
    {
        cout << error_message << endl;
    }
    
    // Ÿ���� �˸´� catch ���� - 1 
    try
    {
        throw -1; // catch (int x) ���� 
    }
    catch (int x)
    {
        cout << "Catch Integer " << x << endl;
    }
    catch (string error_message)
    {
        cout << error_message << endl;
    }
    
    // Ÿ�� �˸´� catch ���� - 2
	try
    {
        throw "My error message"; // catch (const char *error_message) ���� 
    }
    catch (double x)
    {
        cout << "Catch double" << endl;
    }
    catch (const char *error_message)
    {
        cout <<  "const char * " << error_message << endl;
    } 

    return 0;
}
