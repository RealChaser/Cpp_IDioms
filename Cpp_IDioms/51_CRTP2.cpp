#include <iostream>
using namespace std;
// CRTP 기술로 가상함수가 아닌 함수를 가상함수 처럼 보이게 하기..
// MS 라이브러리인 ATL 이 활용하는 기술
template<typename T> class Window
{
public:
	void msgLoop() // void msgLoop( Window* this )
	{
	//	click(); // this->click()
	//	((MyWindow*)this)->click(); // 자식 호출.

		((T*)this)->click(); // 자식 호출.
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