#include <iostream>
using namespace std;


class X
{
public:
	int a;
	char b;

	X() : a(-999), b('C') {}  // Initialize with default values, if any.
	X & setA(int i) { a = i; return *this; } // non-const function
	X & setB(char c) { b = c; return *this; } // non-const function

	static X create() {
		return X();
	}
};

std::ostream & operator << (std::ostream & o, X const & x)
{
	o << x.a << " " << x.b;
	return o;
}

int main(void)
{
	// The following code uses the named parameter idiom.
	std::cout << X::create().setA(10).setB('Z') << std::endl;
}