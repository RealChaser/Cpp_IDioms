// 52_shared_from_this
#include <iostream>
#include <memory>
#include <conio.h>
#include <Windows.h>
using namespace std;
// enable_shared_from_this : this�� ����ؼ� ��������� ���� �Ҽ� �ְ�
class Thread : public enable_shared_from_this<Thread> // CRTP
{
	shared_ptr<Thread> holdSelf; // �ڽ��� ��������� �����ϱ� ����.
public:
	virtual ~Thread() { cout << "Thread �ı�" << endl; }

	// ���� �����ڿ��� ���� �Ǹ� �ȵ�...
	// ������ ���鶧 ���� ��� ����
	// Thread() { holdSelf = this; }

	void run() 
	{
	//	holdSelf = this; // �̷��� �ص� �ɱ� ?
		
		holdSelf = shared_from_this(); // �ܺο��� ���� shared_ptr<>
								// �� ��������� �����ϰ� �Ѵ�.

		CreateThread(0, 0, threadstart, this, 0, 0); 
	}

	static DWORD __stdcall threadstart(void* p)
	{
		Thread* self = static_cast<Thread*>(p);
		self->Main();

		// ������ ����� ���� ����� �ٿ��� �ڽ��� �ı� �Ѵ�.
		self->holdSelf.reset(); // �̼��� Thread ��ü �ı�..
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
		// ������ ��ü�� ����Ʈ ������ ����..
		shared_ptr<MyThread> p(new MyThread);
		p->run();
	}

	_getch();
}
/*
shared_ptr<int> p1(new int);
shared_ptr<int> p2(p1); // ������� 2
int* t = p1.get();

shared_ptr<int> p3(t); // 
*/
