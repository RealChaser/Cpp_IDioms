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
// 1. 함수템플릿의 인자는 암시적 추론될수 있다.
// 2. 함수템플릿의 리턴타입은 암시적 추론될수 있다.
// 3. T 타입으로의 암시적 변환을 위한 변환연산자의 템플릿은
//    좌변을 통해서 암시적 추론될수 있다.

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

	// 변환 연산자 함수
	//operator int() { return 0; } // getRandomN 이 int로 변환이 필요 할때 호출된다.

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






