#include <iostream>
#include <vector>
#include <list>
using namespace std;


template<typename T> void show(T& c)
{
	for (auto& n : c)
	{
		cout << n << endl;
	}
	return;
}
/*
int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	show<list<int>>(s);
	show(s);
}
*/
// 1. �Լ����ø��� ���ڴ� �Ͻ��� �߷еɼ� �ִ�.
// 2. �Լ����ø��� ����Ÿ���� �Ͻ��� �߷еɼ� �ִ�.
// 3. T Ÿ�������� �Ͻ��� ��ȯ�� ���� ��ȯ�������� ���ø���
//    �º��� ���ؼ� �Ͻ��� �߷еɼ� �ִ�.

/*
template<typename Container> Container getRandomN(int n)
{
	Container c;

	for (size_t i = 0; i < n; ++i)
		c.insert(c.end(), rand());

	return c;
}
*/

class getRandomN
{
	int n;
public:
	getRandomN(int a) : n(a) {}

	// ��ȯ ������ �Լ�
	//operator int() { return 0; } // getRandomN �� int�� ��ȯ�� �ʿ� �Ҷ� ȣ��ȴ�.

	template<typename T> operator T()
	{
		T c;

		for (size_t i = 0; i < n; ++i)
			c.insert(c.end(), rand());

		return c;
	}
};

int main()
{
	//list<int> s = getRandomN(10); // error
	//list<int> s = getRandomN<list<int>>(10); // ok

//	getRandomN g(10);
//	list<int> s = g;

	list<int> s = getRandomN(10);

	show(s);
}






