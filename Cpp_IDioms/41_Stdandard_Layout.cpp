#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

// www.cppreference.com  - standard layout
// 1. All non - static data members have the same access control
// 2. Has no virtual functions or virtual base classes
// 3. Has no non - static data members of reference type
// 4. All non - static data members and base classes are themselves standard layout types

// standard layout : 메모리구조가 C와 동일한 모양을 나타내는 것.
//					다른 언어와 메모리를 교환하기 위해서 생긴 개념.

class A
{
//	int x;
};

class B : public A
{
//	int a;
//public:
//	int b;
	//virtual void foo() {}
};

int main()
{
//	B b = { }
	cout << boolalpha;
	cout << is_standard_layout<B>::value << endl;
}


