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
//	d.x = 20; // Test에 도 있고 FallBAck 에도 x가 있다면 error.

	cout << sizeof(foo<Derived>(0)) << endl;
}
