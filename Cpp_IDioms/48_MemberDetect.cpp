#include <iostream>
using namespace std;

// 1. sizeof(�Լ�ȣ����) : ��¥ �Լ� ȣ��ƴ�.. ��� �Լ����� �����ϴ°�
// 2. ... �Լ��� ������ ���õ�..
//    �Ͻ��� ��ȯ�� �켱�� ��..

//char  foo(int); // { return 0; }
short foo(int*);// { return 0; }
int   foo(...); // { return 0; }

int main()
{
	// �Ʒ� ǥ���� �Լ��� ȣ���� �ƴ�.
	// ��� �Լ��� ���õǴ����� �����ϴ� �� �Դϴ�.
	cout << sizeof( foo(0) ) << endl;
	
}
