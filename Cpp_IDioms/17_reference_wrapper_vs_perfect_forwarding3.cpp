#include <iostream>
#include <vector>
#include <functional>
using namespace std;
using namespace std::placeholders;

void foo(int a, int& b) { cout << "foo" << endl; b = 100; }

int main()
{
	int n1 = 10;

	function<void(int)> f;

	// bind�� ���ڸ� �����Ҷ� ���纻, �� ������ �����ϰ� �ְ� �ȴ�...
	// ������ �����Ҽ� ������.
	//f = bind(&foo, _1, n1); // foo�� 2��°���ڸ� n1���� �����Ѵ�.
	
//	f = bind(&foo, _1, &n1); // n1�� �ּҸ� �����Ѵ�. ������ �������� ��������
								// �ּҰ� �ٽ� ������ ���ؾ� �Ѵ�. error

	//reference_wrapper<int> r1 = n1;
	//f = bind(&foo, _1, r1); // �ᱹ r1�� n1�� �ּҸ� ��� �ִ�.
							// �׸��� r1�� int& �� ��ȯ �����ϴ�.

	//f = bind(&foo, _1, reference_wrapper<int>(n1) );
	f = bind(&foo, _1, ref(n1)); // ref()�� �ᱹ reference_wrapper<>�� ������ �ݴϴ�.


	f(5); // foo( 5, n1);

	cout << n1 << endl;
}



