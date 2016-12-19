// 52_shared_from_this
#include <iostream>
#include <memory>
#include <conio.h>
#include <Windows.h>
using namespace std;
// enable_shared_from_this : this를 사용해서 참조계수를 공유 할수 있게
class Thread : public enable_shared_from_this<Thread> // CRTP
{
	shared_ptr<Thread> holdSelf; // 자신의 참조계수를 증가하기 위해.
public:
	virtual ~Thread() { cout << "Thread 파괴" << endl; }

	// 절대 생성자에서 증가 되면 안됨...
	// 스레드 만들때 참조 계수 증가
	// Thread() { holdSelf = this; }

	void run() 
	{
	//	holdSelf = this; // 이렇게 해도 될까 ?
		
		holdSelf = shared_from_this(); // 외부에서 만든 shared_ptr<>
								// 의 참조계수를 공유하게 한다.

		CreateThread(0, 0, threadstart, this, 0, 0); 
	}

	static DWORD __stdcall threadstart(void* p)
	{
		Thread* self = static_cast<Thread*>(p);
		self->Main();

		// 스레드 종료시 참조 계수를 줄여서 자신을 파괴 한다.
		self->holdSelf.reset(); // 이순간 Thread 객체 파괴..
		return 0;
	}

	virtual void Main() = 0;
};

class MyThread : public Thread
{
	int data;
public:
	virtual void Main()
	{
		cout << "MyThread Main" << endl;
		data = 10;
	}
};

int main()
{
	//MyThread* p = new MyThread;

	{
		// 스레드 객체와 스마트 포인터 문제..
		shared_ptr<MyThread> p(new MyThread);
		p->run();
	}

	_getch();
}
/*
shared_ptr<int> p1(new int);
shared_ptr<int> p2(p1); // 참조계수 2
int* t = p1.get();

shared_ptr<int> p3(t); // 
*/
