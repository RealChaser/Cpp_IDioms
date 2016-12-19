#include <iostream>
#include <string>
using namespace std;

void foo(int& r)  { cout << "int&" << endl; }
void foo(int&& r) { cout << "int&&" << endl; }

int main()
{
	string s1;

	s1 = "hello"; // s1      : lvalue, ���ʿ� �ִ�. �̸��� �ִ�
				  // "hello" : rvalue, �����ʿ� �ִ�. �̸��� ����.

	foo(s1);		// lvalue reference
	foo("hello"s);	// rvalue reference
	foo(move(s1));  // rvalue reference ȣ��, ������ �̸��� �ִ�!!
					// xvalue ( eXpire value )
					// �̸��� ������, rvalue �� ����ȴ�.

	string s2 = s1; // ���� ������
	string s3 = string("hello"); // move ������ ȣ��
	string s4 = move(s1); //  �̸��� ������ move ������ ȣ��.

	cout << s2 << endl;
}
	
//  lvalue(s1)      xvalue(move(s1))      prvalue ("hello", string("a"))
//			 glvalue( �̸��� �ִ�)     rvalue(moveȣ��. ������ ������)



