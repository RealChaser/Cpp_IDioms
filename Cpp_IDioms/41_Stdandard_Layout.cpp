#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

// www.cppreference.com  - standard layout
// 1. All non - static data members have the same access control
// 2. Has no virtual functions or virtual base classes
// 3. Has no non - static data members of reference type
// 4. All non - static data members and base classes are themselves standard layout types

// standard layout : �޸𸮱����� C�� ������ ����� ��Ÿ���� ��.
//					�ٸ� ���� �޸𸮸� ��ȯ�ϱ� ���ؼ� ���� ����.

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


