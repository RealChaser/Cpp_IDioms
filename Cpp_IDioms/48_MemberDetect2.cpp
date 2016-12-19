#include <iostream>
using namespace std;

// Member Detect  : Ư�� ��� data�� �ִ��� Ȯ���ϴ� ���.

template<typename T, T> struct Check;

//Check<int, 10> c;
// �Ʒ� ǥ���� Test�� x����� ������ ok.. ������ error
//Check<int(Test::*), &Test::x> c2;

class Test
{
private:
	int x;
};

//char  foo( Check<int Test::*, &Test::x>* );
//short foo(...) ;

// ġȯ ���д� ������ �ƴ϶� �Լ� �����ε����� ���� �ȴٴ� Ư¡�� �̿��ѱ��
// private �� x�� ������ ġȯ ���а� �ƴ϶�.. error..
template<typename T> char  foo( Check<int T::*, &T::x>* );
template<typename T> short foo(...) ;

int main()
{
	cout << sizeof(foo<Test>(0)) << endl;
}



/*
	int Test::*p = &Test::x; // ��� data �ּ� ���ϴ� ��.
					// Test �ȿ� x�� ��ġ.. offset 0
	Test t;

	t.*p = 10; // t.x = 10
	*/
//}





