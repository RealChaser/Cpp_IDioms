#include <iostream>
using namespace std;
// CRTP ����� �����Լ��� �ƴ� �Լ��� �����Լ� ó�� ���̰� �ϱ�..
// MS ���̺귯���� ATL �� Ȱ���ϴ� ���
template<typename T> class Window
{
public:
	void msgLoop() // void msgLoop( Window* this )
	{
	//	click(); // this->click()
	//	((MyWindow*)this)->click(); // �ڽ� ȣ��.

		((T*)this)->click(); // �ڽ� ȣ��.
	}
	void click() { cout << "window click" << endl; }
};

class MyWindow : public Window<MyWindow>
{
public:
	void click() { cout << "MyWindow click" << endl; }
};

int main()
{
	MyWindow mw;
	mw.msgLoop();
}