#include <iostream>
using namespace std;

template<typename T, T> struct Check;

class Test
{
private:
	int x;
};

struct FallBack { int x; };

struct Derived : Test, FallBack {};


template<typename T> char  foo(Check<int FallBack::*, &T::x>*);
template<typename T> short foo(...);

int main()
{
//	Derived d;
//	d.x = 20; // Test�� �� �ְ� FallBAck ���� x�� �ִٸ� error.

	cout << sizeof(foo<Derived>(0)) << endl;
}
