#include <iostream>
#include <thread> // C++11 ������
using namespace std;

void foo(int& a, int n)
{
	a = 10;
}

int main()
{
	int n = 0;
	thread t(&foo, ref(n), n); // �� ���� �����尡 �����˴ϴ�. �̼��� n�� ��������� ���޵ɱ��?
							//							���� ������� ���޵ɱ�� ?
						// �� ������� ��������ϴ�.
						// �׷��� �������Լ� ���ڰ� ������� ref()�� ��� ������ �մϴ�..

	t.join();
	cout << n << endl; // 0 ? 10
}





